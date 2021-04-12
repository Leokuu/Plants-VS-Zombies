#ifndef SCENE_H
#define SCENE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QPoint>
#include "mainwindow.h"
#include "action.h"
#include "card.h"
#include "zombies.h"
#include "plants.h"

#define mapWdith  1400  //地图宽度
#define mapHeight 600   //地图长度
#define moveTime  600   //移动时间
#define chooserWidth  522
#define chooserHeight 87
#define panelWidth    465
#define panelHeight   513
#define mapPreX     82
#define mapPreY     100

class MainWindow;
class Action;
class Card;
class Plants;
class Zombies;
class Bullets;

//僵尸链表函数
typedef struct ZombieARRAY
{
    Zombies *current;
    ZombieARRAY *latter;
} *qaq;

class Scene : public QWidget
{
    Q_OBJECT

public:
    explicit Scene(MainWindow *parent = nullptr);
    void mapDaytime();               //加载地图：白天
    static QPoint getPlacePostion(int x,int y) {return Scene::placePostion[x][y];}
    void setArrayPlants(int x, int y, Plants *p) {arrayPlants[x][y] = p;}
    char getArrayPlants(int x, int y) {return arrayPlants[x][y]>0?1:0;}
    void zombiesManage();       //僵尸管理函数
    void bulletManage();        //子弹管理

    ZombieARRAY *zombieArray[5];

public slots:
    void startFighting();       //开始战斗
    void placeOnePlant(int);    //放置植物
    void chooseShover();        //选择铲子
    void fightDetecion();       //战斗检测

signals:
    void mapStop();             //地图结束移动 connect in Scene
    void startLoadCard();       //开始加载卡片 connect in Scene

private:
    MainWindow *myWindow;       //当前窗口
    Card *myCard;               //卡片对象
    QLabel *map;                //地图
    QLabel *chooser;            //上场植物槽
    QLabel *cardpanel;          //全部植物选择槽
    QLabel *shoverSlot;         //铲子槽
    QPushButton *shover;        //铲子
    QPushButton *startButton;   //开始战斗按钮
    Plants *arrayPlants[9][5];
    static QPoint placePostion[9][5];    

    QTimer *timer;
};


#endif // SCENE_H
