#include "scene.h"
#include "mainwindow.h"
#include "card.h"
#include "action.h"
#include <QLabel>
#include <QDebug>
#include <QMouseEvent>

Scene::Scene(MainWindow *parent)
{
    this->myWindow = parent;
    this->myCard = new Card(myWindow);          //创建card对象
    int i,j;
    for (i=0; i<9; i++)
        for (j=0; j<5; j++)
            this->arrayPlants[i][j] = new Plants(myWindow);

    for (i=0; i<9; i++)         //生成位置坐标
        for (j=0; j<5; j++)
            Scene::placePostion[i][j] = QPoint(75+i*mapPreX, 90+j*mapPreY);
}

void Scene::mapDaytime()
{
    //加载地图
    this->map = new QLabel(myWindow);                            //加载地图
    map->setPixmap(QPixmap("../../graphics/Map/map0.jpg"));    //加载地图，以pro文件为起点
    map->setGeometry(0, 0, mapWdith, mapHeight);
    map->setMouseTracking(true);

    //地图初始移动
    Action *myAction = new Action();     //创建动画对象
    myAction->widgetMove(map, windowWidth-mapWdith, 0, moveTime);

    //加载上场植物选择糟
    this->chooser = new QLabel(myWindow);
    chooser->setPixmap(QPixmap("../../graphics/Screen/ChooserBackground.png"));
    chooser->setStyleSheet("border:2px groove saddlebrown;border-radius:8px;");
    chooser->setGeometry(0, 0, chooserWidth, chooserHeight);
    chooser->setMouseTracking(true);
    chooser->hide();
    //加载植物种植选择糟
    this->cardpanel = new QLabel(myWindow);
    cardpanel->setPixmap(QPixmap("../../graphics/Screen/PanelBackground.png"));
    cardpanel->setStyleSheet("border:2px groove sienna;border-radius:8px;");
    cardpanel->setGeometry(0, chooserHeight, panelWidth, panelHeight);
    cardpanel->hide();

    //地图移动结束，进行植物选择
    connect(myAction, &Action::moveFinish, [=](){     //地图停止移动
        chooser->show();
        cardpanel->show();
        emit startLoadCard();
                 //开始选择卡片
    });

    //选上场植物
    connect(this, &this->startLoadCard, [=](){

        this->myCard->cardShow();          //开始卡片选择

        this->startButton = new QPushButton(myWindow);                 //创建开始战斗按钮
        startButton->setIcon(QIcon("../../graphics/Screen/StartButton.png")); //设置图表
        startButton->setIconSize(QSize(154, 37));           //设置图片大小
        startButton->setGeometry(157, 547, 154, 37);        //设置位置，大小
        startButton->hide();                                //先隐藏

        connect(myCard, &Card::CanStartFighting, [=](){     //选卡结束后显示开始战斗按钮
            startButton->show();
            connect(startButton, &QPushButton::clicked, this, &this->startFighting);   //一大波僵尸即将来临
        });

        connect(myCard, &Card::CannotStartFighting, [=](){ //上场植物卡满选下来一张后隐藏开始战斗按钮
            startButton->hide();
        });

    });

}

void Scene::startFighting()         //开始战斗
{
    this->startButton->hide();
    this->cardpanel->hide();

    for (int k=0; k<cardNumber; k++)
        if (myCard->getCardState(k) == -1)
            myCard->hideAButton(k);

    Action *myAction = new Action();    //创建动画对象
    myAction->widgetLocate(this->map, -180, 0, moveTime);

    myCard->fightingMode();             //开始战斗
    connect(myCard, &Card::PlcaePlant, this, this->placeOnePlant);
}

void Scene::placeOnePlant(int n)    //放置植物,n是植物代号
{

    this->myCard->setButtonState(n, 0);    //隐藏图标
    Plants *plant;

    for (int k=0; k<chooserMax; k++) qDebug() << myCard->getChooserPlant(k);
    qDebug() <<"Now Plant : " << n;


    switch (n)
    {
        case peashooter: plant = new PeaShooter(myWindow);break;
        case sunflower: plant = new SunFlower(myWindow);break;
        case wallnut: plant = new WallNut(myWindow);break;
        case cherrybomb: plant = new CherryBomb(myWindow);break;
        case squash: plant = new Squash(myWindow);break;
        case potatomine: plant = new PotatoMine(myWindow);break;
        case snowpea: plant = new SnowPea(myWindow);break;
        case chomper: plant = new Chomper(myWindow);break;
        case repeaterpea: plant = new RepeaterPea(myWindow);break;
        default: plant = new PeaShooter(myWindow);break;
    }

    //放置植物
    plant->placeAPlant();

    connect(plant, &Plants::placePostion, [=](int x, int y){        
        qDebug() << "Place a plant";
        this->setArrayPlants(x, y ,plant);
        this->myCard->setButtonState(n ,1); //1 恢复 2冷却
    });

    connect(plant, &Plants::cancelPlace, [=](){        
        qDebug() << "Do not place";
        this->myCard->setButtonState(n, 1);
    });

}


/*   card对应表
 * 0  豌豆射手
 * 1  向日葵
 * 2  坚果墙
 * 3  樱桃炸弹
 * 4  冰豌豆射手
 * 5  倭瓜
 * 6  食人花
 */





