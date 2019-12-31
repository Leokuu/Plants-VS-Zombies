#ifndef PLANTS_H
#define PLANTS_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "mainwindow.h"


class Plants
{
public:
    explicit Plants(MainWindow *mainwindow = 0);
    ~Plants();

    void mode();
    void fight();
    void injured();

private:

protected:
    MainWindow *mywindow;
    int hp;         //生命值
    int atk;        //攻击力
    int speed;      //攻击速度
    int range;      //射程
    int cooling;    //冷却
    int cost;       //花费
    int state;      //当前状态

};


#endif // PLANTS_H

//https://wenku.baidu.com/view/084da852a22d7375a417866fb84ae45c3b35c280.html

/*********************** 植物数据 **********************
 *
 *              HP  ATK  SPEED  RANGE  COOLING  COST
 *  豌豆射手    100   20   1400   ALL     7500    100
 *
 *
 *
 *
 *
 *
 *
 *****************************************************/
















