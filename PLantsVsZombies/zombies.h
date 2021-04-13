#ifndef ZOMBIES_H
#define ZOMBIES_H

#include <QWidget>
#include <QMovie>
#include <mainwindow.h>

class Zombies;

typedef QVector<Zombies *> ZombiesVector;

//--------  僵尸父类  --------//
class Zombies : public QWidget
{
    Q_OBJECT

public:
    explicit Zombies(MainWindow *parent = nullptr, int line = 0);
    ~Zombies();
    virtual void fight();           //攻击
    virtual void injury(int);       //僵尸被攻击
    virtual void injuryBlink();     //被攻击闪烁
    virtual void creatAZombies();   //生成僵尸
    virtual int getPostion() {return label->pos().x()+66;}  //返回当前位置
    virtual int getState() {return this->state;}

    static void addAZombie(MainWindow *parent, uint8_t line);
    static bool ifEmptyInALine(uint8_t line);
    static Zombies *firstZombie(uint8_t line);

protected:
    MainWindow *myWindow;
    QString path;
    QPoint postion;
    QSize modeSize;
    QLabel *label;
    Action *action;
    QMovie *myGif;
    int line;
    int frameNum;
    int hp;
    int atk;
    int speed;
    int state;

    static ZombiesVector zombiesVector[5];

    void zombieInit(int frameNum,int hp, int atk,
                    int speed, int state); //僵尸初始化

};


//------  普通僵尸 ------//
class NormalZombie : public Zombies
{
    Q_OBJECT

public:
    explicit NormalZombie(MainWindow *parent = nullptr, int line = 0);
    ~NormalZombie();
    //virtual void currentMode();     //僵尸形态
    virtual void fight();           //攻击
    virtual void injury(int);       //僵尸被攻击
    virtual void creatAZombies();   //生成僵尸
};

#endif // ZOMBIES_H
