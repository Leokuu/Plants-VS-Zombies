#ifndef PLANTS_H
#define PLANTS_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "mainwindow.h"

#define peashooter  0
#define sunflower   1
#define wallnut     2
#define cherrybomb  3
#define squash      4
#define potatomine  5
#define snowpea     6
#define chomper     7
#define repeaterpea 8

class Plants : public QWidget
{
    Q_OBJECT

public:
    explicit Plants(MainWindow *parent = nullptr);
    ~Plants();
    virtual void aPlantAdd(int x,int y);     //放置植物
    virtual void fight();               //攻击模式
    virtual void injured();             //受伤
    virtual void placeAPlant();         //放置植物 1 放置 ，0 取消
    virtual void aFgiht();    //一次攻击
    virtual void setFightState(char a) {fightState = a;}  //调整攻击状态

signals:
    void placePostion(int x, int y);
    void cancelPlace();

private:

protected:
    MainWindow *myWindow;
    QString path;
    QMovie *pathBullet, *pathExplosion;
    QPoint postion;     //地图位置
    int hp;             //生命值
    int atk;            //攻击力
    int speed;          //攻击速度
    int range;          //射程
    int cooling;        //冷却
    int cost;           //花费
    int state;          //当前状态
    QSize modeSize;     //模型大小
    char fightState;    //攻击状态
    void plantInit(int hp, int atk, int speed,
                   int range,int cooling, int cost);   //植物初始化


};


/*********************************
             豌豆射手

*********************************/

class PeaShooter : public Plants
{
    Q_OBJECT

public:
    explicit PeaShooter(MainWindow *parent = nullptr);
    ~PeaShooter();
    virtual void fight();       //攻击模式
    virtual void injured();     //受伤
    virtual void aFgiht();      //一次攻击

private:

protected:
};

/*********************************
             坚果墙

*********************************/
class WallNut : public Plants
{
    Q_OBJECT

public:
    explicit WallNut(MainWindow *parent = nullptr);
    ~WallNut();
    virtual void fight();       //攻击模式
    virtual void injured();     //受伤

private:

protected:
};

/*********************************
             向日葵

*********************************/
class SunFlower : public Plants
{
    Q_OBJECT

public:
    explicit SunFlower(MainWindow *parent = nullptr);
    ~SunFlower();
    virtual void fight();       //攻击模式
    virtual void injured();     //受伤

private:

protected:
};

/*********************************
             樱桃炸弹

*********************************/
class CherryBomb : public Plants
{
    Q_OBJECT

public:
    explicit CherryBomb(MainWindow *parent = nullptr);
    ~CherryBomb();
    virtual void fight();       //攻击模式
    virtual void injured();     //受伤

private:

protected:
};

/*********************************
             倭瓜

*********************************/
class Squash : public Plants
{
    Q_OBJECT

public:
    explicit Squash(MainWindow *parent = nullptr);
    ~Squash();
    virtual void fight();       //攻击模式
    virtual void injured();     //受伤

private:

protected:
};

/*********************************
             土豆地雷

*********************************/
class PotatoMine : public Plants
{
    Q_OBJECT

public:
    explicit PotatoMine(MainWindow *parent = nullptr);
    ~PotatoMine();
    virtual void fight();       //攻击模式
    virtual void injured();     //受伤

private:

protected:
};

/*********************************
             冰豌豆射手

*********************************/
class SnowPea : public Plants
{
    Q_OBJECT

public:
    explicit SnowPea(MainWindow *parent = nullptr);
    ~SnowPea();
    virtual void fight();       //攻击模式
    virtual void injured();     //受伤
    virtual void aFgiht();      //一次攻击

private:

protected:
};

/*********************************
             食人花

*********************************/
class Chomper : public Plants
{
    Q_OBJECT

public:
    explicit Chomper(MainWindow *parent = nullptr);
    ~Chomper();
    virtual void fight();       //攻击模式
    virtual void injured();     //受伤

private:

protected:
};

/*********************************
             豌豆爸爸

*********************************/
class RepeaterPea : public PeaShooter
{
    Q_OBJECT

public:
    explicit RepeaterPea(MainWindow *parent = nullptr);
    ~RepeaterPea();
    virtual void fight();       //攻击模式

private:

protected:
};

#endif // PLANTS_H

/*********************** 植物数据 *******************************
 *
 * NUM    NMAE     HP  ATK  SPEED  RANGE  COOLING  COST   frame
 *  0   豌豆射手   300   20   1400   ALL     7500    100    13
 *
 *
 *
 *
 *
 *
 *
 ***************************************************************/
















