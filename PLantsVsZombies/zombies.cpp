#include "zombies.h"
#include "mainwindow.h"
#include "plants.h"
#include "action.h"
#include <QMovie>
#include <QDebug>
#include <QLabel>
#include <QTimer>

//-----------------------------------------------------------------------
//             僵尸父类
//
//------------------------------------------------------------------------
ZombiesVector Zombies::zombiesVector[5] = {};

Zombies::Zombies(MainWindow *parent, int line)
{
    this->myWindow = parent;
    this->line = line;
}

void Zombies::zombieInit(int frameNum, int hp, int atk, int speed, int state)
{
    this->frameNum = frameNum;
    this->hp = hp;
    this->atk = atk;
    this->speed = speed;
    this->state =state;
}

void Zombies::creatAZombies()
{

}

void Zombies::fight()
{

}

void Zombies::injury(int atk)
{
    atk = atk;
}

void Zombies::injuryBlink()
{
    //QTimer *timer = new QTimer(this);
    //timer->start();
}

Zombies::~Zombies()
{

}

////////////////////////////////////////////////////////////
// static
void Zombies::addAZombie(MainWindow *parent, uint8_t line)
{
    // 在指定行数添加一只僵尸
    Zombies *zombie = new NormalZombie(parent, line);
    Zombies::zombiesVector[line].push_back(zombie);

}


Zombies *Zombies::firstZombie(uint8_t line)
{
    ZombiesVector &zv = Zombies::zombiesVector[line];

    if (zv.size() == 0)
        return nullptr;

    ZombiesVector::iterator i = zv.begin();
    Zombies *firstZombie = *i;

    for (i+=1; i<zv.end(); i++)
    {
        if (firstZombie->getPostion() > (*i)->getPostion())
            firstZombie = *i;
    }

    return firstZombie;
}


bool Zombies::ifEmptyInALine(uint8_t line)
{
    if (Zombies::zombiesVector[line].size() == 0)
        return true;
    else
        return false;
}


//----------------------------------------------------------------------
//              普通僵尸
//
//------------------------------------------------------------------------
NormalZombie::NormalZombie(MainWindow *parent, int line)
{
    this->myWindow = parent;
    this->line = line;
    this->path = QString("../graphics/Zombies/Zombie/");
    zombieInit(22, 270, 100, 4700, 0);

    creatAZombies();
}

//----------- 生成僵尸 -----------//
void NormalZombie::creatAZombies()
{
    this->myGif = new QMovie();
    //myGif->setFileName(QString("%1ZombieHead.gif").arg(path));
    myGif->setFileName(QString("%1Zombie.gif").arg(path));
    this->label = new QLabel(myWindow);
    label->setMovie(myGif);
    label->setGeometry(800, 20+100*line, 166, 144);
    label->show();
    myGif->start();

    this->action = new Action();
    action->widgetMove(label, -82*13, 0, 6000*13);     //平动

}

void NormalZombie::fight()
{

}

void NormalZombie::injury(int atk)
{
    this->hp -= atk;
    QTimer *timer0 = new QTimer();
    QMovie *m = new QMovie(QString("%1ZombieHead.gif").arg(path));
    QLabel *l = new QLabel(myWindow);
    if (hp <= 60 && state == 0)     //掉头
    {
        this->state = 1;
        myGif->stop();
        myGif->setFileName(QString("%1ZombieLostHead.gif").arg(path));
        myGif->start();

        l->setMovie(m);
        l->setGeometry(getPostion() ,20+100*line, 166, 190);
        m->start();
        l->show();
        timer0->start(1000);
    }

    connect(timer0, &QTimer::timeout, [=]()mutable{
        timer0->stop();
        delete m;
        delete l;
    });

    QTimer *timer1 = new QTimer();
    if (hp <=0 && state == 1)
    {
        this->state = 2;
        myGif->stop();
        myGif->setFileName(QString("%1ZombieDie.gif").arg(path));
        myGif->start();
        timer1->start(2000);
        action->widgetMove(label, -10, 0, 500);
    }
    connect(timer1, &QTimer::timeout, [=]()mutable{this->state = 3;});
}

NormalZombie::~NormalZombie()
{
    qDebug() << "NormalZombie::~NormalZombie()";
    label->hide();
}




