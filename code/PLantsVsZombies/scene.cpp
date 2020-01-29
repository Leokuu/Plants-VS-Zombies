#include "scene.h"
#include "mainwindow.h"
#include "card.h"
#include "action.h"
#include "zombies.h"
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
            this->arrayPlants[i][j] = nullptr;

    for (i=0; i<9; i++)         //生成位置坐标
        for (j=0; j<5; j++)
            Scene::placePostion[i][j] = QPoint(68+mapPreX/2+i*mapPreX, 75+mapPreY/2+j*mapPreY);
}

void Scene::mapDaytime()
{
    //加载地图
    this->map = new QLabel(myWindow);                            //加载地图
    map->setPixmap(QPixmap("../../graphics/Map/map0.jpg"));    //加载地图，以pro文件为起点
    map->setGeometry(0, 0, mapWdith, mapHeight);
    map->setMouseTracking(true);

    Action *Start = new Action();
    Start->widgetMove(map, 0, 0, 1500);

    //地图初始移动
    Action *myAction = new Action();     //创建动画对象
    connect(Start, &Action::moveFinish, [=](){     //地图停止移动
        myAction->widgetMove(map, windowWidth-mapWdith, 0, moveTime);
    });

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
    //加载铲子
    this->shoverSlot = new QLabel(myWindow);
    shoverSlot->setPixmap(QPixmap("../../graphics/Screen/shovelSlot.png"));
    shoverSlot->setGeometry(522, 0, 84, 87);
    shoverSlot->hide();

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
    disconnect(startButton, 0,0,0);
    this->startButton->hide();
    this->cardpanel->hide();
    this->shoverSlot->show();

    for (int k=0; k<cardNumber; k++)
        if (myCard->getCardState(k) == -1)
            myCard->hideAButton(k);

    Action *myAction = new Action();    //创建动画对象
    myAction->widgetLocate(this->map, -180, 0, moveTime);

    myCard->fightingMode();             //开始战斗
    connect(myCard, &Card::PlcaePlant, this, this->placeOnePlant);

    //铲子
    this->shover = new QPushButton(myWindow);
    shover->setFlat(true);
    shover->setIcon(QIcon(QString("../../graphics/Screen/shovel.png")));                    //设置图表
    shover->setIconSize(QSize(70,74));
    shover->setGeometry(522, 0, 70, 74);     //设置位置，大小
    shover->setMouseTracking(true);
    shover->show();
    connect(shover, &QPushButton::pressed, this, &Scene::chooseShover);

    zombiesManage();        //僵尸管理函数
}

void Scene::chooseShover()
{
    Action *action = new Action(myWindow);
    QLabel *label = new QLabel(myWindow);
    label->hide();
    disconnect(shover, &QPushButton::pressed, 0,0);

    action->widgetMouse(shover, label, QSize(70, 74));
    connect(action, &Action::FinishPlace, [=](QPoint postion){
        qDebug() << "Remove a plant";
        QPoint p = QPoint( (postion.x()-75)/mapPreX, (postion.y()-90)/mapPreY );
        qDebug() << "shover : " << p.x() << p.y();
        shover->move(522, 0);

        connect(shover, &QPushButton::pressed, this, &Scene::chooseShover);
    });

    connect(action, &Action::DonotPlace, [=](){
        qDebug() << "Do not place";
        shover->move(522, 0);
    });
}

void Scene::placeOnePlant(int n)    //放置植物,n是植物代号
{

    this->myCard->setButtonState(n, 0);    //隐藏图标
    Plants *plant;

   // for (int k=0; k<chooserMax; k++) qDebug() << myCard->getChooserPlant(k);
    qDebug() <<"Now Plant : " << n;


    switch (n)
    {
        case peashooter: plant = new PeaShooter(myWindow);break;
        case sunflower:  plant = new SunFlower(myWindow);break;
        case wallnut:    plant = new WallNut(myWindow);break;
        case cherrybomb: plant = new CherryBomb(myWindow);break;
        case squash:     plant = new Squash(myWindow);break;
        case potatomine: plant = new PotatoMine(myWindow);break;
        case snowpea:    plant = new SnowPea(myWindow);break;
        case chomper:    plant = new Chomper(myWindow);break;
        case repeaterpea:plant = new RepeaterPea(myWindow);break;
        default: plant = new PeaShooter(myWindow);break;
    }

    //放置植物
    plant->placeAPlant();

    connect(plant, &Plants::placePostion, [=](int x, int y){        
        qDebug() << "Place a plant";
        plant->setFightState(1);
        this->setArrayPlants(x, y ,plant);
        this->myCard->setButtonState(n ,1); //1 恢复 2冷却
    });

    connect(plant, &Plants::cancelPlace, [=](){        
        qDebug() << "Do not place";
        this->myCard->setButtonState(n, 1);
    });

}

void Scene::zombiesManage()         //僵尸管理函数
{
    int i;
    for (i=0; i<5; i++)
    {
        zombieArray[i] = new ZombieARRAY;
        zombieArray[i]->current = nullptr;
        zombieArray[i]->latter = nullptr;
        firstZombie[i] = nullptr;
    }

    //左键出僵尸
    connect(myWindow, &MainWindow::leftPress, [=](){
        QPoint p = myWindow->getMousePostion();
        int n = (p.y()-80)/100;
        ZombieARRAY *fp0 = zombieArray[n];

        qDebug() << "I want a zombie in line: " << n;
        qDebug() << p.x() << p.y();

        while (fp0->latter != nullptr) fp0 = fp0->latter;
        ZombieARRAY *fp1 = new ZombieARRAY;
        fp1->current = new NormalZombie(myWindow, n);
        fp1->latter = nullptr;
        fp0->latter = fp1;
    });

    QTimer *timer = new QTimer(this);
    timer->start(timerFrequency);           //60Hz刷新率
    connect(timer, &QTimer::timeout, [=](){
        int i;
        ZombieARRAY *fp, *fp0;
        for (i=0; i<5; i++)     //清除死亡僵尸
        {
            fp = zombieArray[i];
            while (1)
            {
                if (fp->latter == nullptr) break;
                //qDebug() << "zombie state : " << fp->latter->current->getState();
                if (fp->latter->current->getState() == 3)
                {
                    fp0 = fp->latter->latter;
                    delete fp->latter->current;
                    qDebug() << "-----delete------";
                    fp->latter = fp0;
                }
                else fp = fp->latter;
            }
        }

        for (i=0; i<5; i++)     //选出第一只僵尸
        {
            int pos;
            fp = zombieArray[i];
            if (fp->latter == nullptr) {firstZombie[i] = nullptr; continue;}       //没有僵尸
            fp = fp->latter;
            if (fp->latter == nullptr) firstZombie[i] = fp->current;   //只有一只僵尸
            else while (1)
            {
                pos = firstZombie[i] == nullptr?1000:firstZombie[i]->getPostion();
                if (fp->current->getPostion() < pos)
                    firstZombie[i] = fp->current;
                if (fp->latter == nullptr) break;
                fp = fp->latter;
            }
            if (firstZombie[i] != nullptr) firstZombie[i]->raise();
            if (firstZombie[i] != nullptr && firstZombie[i]->getPostion() > 840)
                firstZombie[i] = nullptr;
            //qDebug() << "first zombie" << firstZombie[2]->getHP();
        }
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





