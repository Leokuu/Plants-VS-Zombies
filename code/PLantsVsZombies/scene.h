#ifndef SCENE_H
#define SCENE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "mainwindow.h"
#include "action.h"
#include "card.h"

#define mapWdith  1400  //地图宽度
#define mapHeight 600   //地图长度
#define moveTime  600  //移动时间
#define chooserWidth  522
#define chooserHeight 87
#define panelWidth    465
#define panelHeight   513

class MainWindow;
class Action;
class Card;

class Scene : public QObject
{
    Q_OBJECT

public:
    explicit Scene(MainWindow *parent = nullptr);
    void mapDaytime();               //加载地图：白天

public slots:
    void startFighting();       //开始战斗

signals:
    void mapStop();             //地图结束移动
    void startLoadCard();       //开始加载卡片

private:
    MainWindow *myWindow;       //当前窗口
    Card *myCard;               //卡片对象
    QLabel *map;                //地图
    QLabel *chooser;            //上场植物槽
    QLabel *cardpanel;          //全部植物选择槽
    QPushButton *startButton;   //开始战斗按钮
};

#endif // SCENE_H
