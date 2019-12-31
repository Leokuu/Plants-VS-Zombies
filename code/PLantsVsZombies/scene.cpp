#include "scene.h"
#include "mainwindow.h"
#include "card.h"
#include "action.h"
#include <QLabel>
#include <QDebug>
#include <QMouseEvent>

Scene::Scene(MainWindow *parent)
{
    Scene::myWindow = parent;
    Scene::myCard = new Card(myWindow);         //创建card对象
}

void Scene::mapDaytime()
{
    //加载地图
    Scene::map = new QLabel(myWindow);                            //加载地图
    map->setPixmap(QPixmap("../../graphics/Map/map0.jpg"));    //加载地图，以pro文件为起点
    map->setGeometry(0, 0, mapWdith, mapHeight);

    //地图初始移动
    Action *myAction = new Action();     //创建动画对象
    myAction->widgetMove(map, windowWidth-mapWdith, 0, moveTime);

    //加载上场植物选择糟
    Scene::chooser = new QLabel(myWindow);
    chooser->setPixmap(QPixmap("../../graphics/Screen/ChooserBackground.png"));
    chooser->setStyleSheet("border:2px groove saddlebrown;border-radius:8px;");
    chooser->setGeometry(0, 0, chooserWidth, chooserHeight);
    chooser->hide();
    //加载植物种植选择糟
    Scene::cardpanel = new QLabel(myWindow);
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
    connect(this, &Scene::startLoadCard, [=](){

        Scene::myCard->cardShow();          //开始卡片选择

        Scene::startButton = new QPushButton(myWindow);                 //创建开始战斗按钮
        startButton->setIcon(QIcon("../../graphics/Screen/StartButton.png")); //设置图表
        startButton->setIconSize(QSize(154, 37));           //设置图片大小
        startButton->setGeometry(157, 547, 154, 37);        //设置位置，大小
        startButton->hide();                                //先隐藏

        connect(myCard, &Card::CanStartFighting, [=](){     //选卡结束后显示开始战斗按钮
            startButton->show();
            connect(startButton, &QPushButton::clicked, this, &Scene::startFighting);   //一大波僵尸即将来临
        });

        connect(myCard, &Card::CannotStartFighting,  [=](){ //上场植物卡满选下来一张后隐藏开始战斗按钮
            startButton->hide();
        });

    });

}

void Scene::startFighting()
{
    Scene::startButton->hide();
    Scene::cardpanel->hide();

    Action *myAction = new Action();    //创建动画对象
    myAction->widgetLocate(Scene::map, -180, 0, moveTime);
}



