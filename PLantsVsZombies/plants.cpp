#include "plants.h"
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QTimer>
#include <QMovie>
#include "action.h"
#include "scene.h"

/*******************************************************************************************
                  植物父类

********************************************************************************************/
Plants::Plants(MainWindow *mainwindow)
{
    this->myWindow = mainwindow;
}

void Plants::placeAPlant()
{
    QPushButton *button = new QPushButton(myWindow);
    button->setFlat(true);
    button->setIcon(QIcon(QString("%1%2.gif").arg(path).arg(0)));
    button->setIconSize(modeSize);
    button->resize(modeSize);
    button->show();
    button->setMouseTracking(true);

    QPixmap *pixmap = new QPixmap(path);
    pixmap->scaled(modeSize, Qt::KeepAspectRatio);
    QLabel *label = new QLabel(myWindow);
    label->setScaledContents(true);
    label->resize(modeSize);
    label->setPixmap(QPixmap(QString("%1%2.gif").arg(path).arg(0)));
    label->show();

    myWindow->setCursor(Qt::BlankCursor);           //隐藏鼠标
    Action *plantAction = new Action(myWindow);     //创建动画
    plantAction->widgetMouse(button, label, this->modeSize);        //跟随鼠标移动

    connect(plantAction, &Action::FinishPlace, [=](QPoint postion){     //放置一个植物
        disconnect(plantAction, 0, 0, 0);           //断开连接
        myWindow->setCursor(Qt::ArrowCursor);       //显示鼠标
        button->hide();
        QPoint p = QPoint( (postion.x()-75)/mapPreX, (postion.y()-90)/mapPreY );
        qDebug() << p.x() << p.y();
        aPlantAdd(p.x(), p.y());
        this->postion = p;
        emit placePostion(p.x(), p.y());
    });

    connect(plantAction, &Action::DonotPlace, [=](){    //右键取消
        disconnect(plantAction, 0, 0, 0);
        myWindow->setCursor(Qt::ArrowCursor);       //显示鼠标
        button->hide();
        emit cancelPlace();
    });
}

void Plants::aPlantAdd(int x,int y)           //生成植物模型
{
    QMovie *myGif = new QMovie(QString("%1%2.gif").arg(path).arg(1));
    QLabel *aPlant = new QLabel(myWindow);
    aPlant->setScaledContents(true);
    aPlant->setMovie(myGif);
    aPlant->setMouseTracking(true);
    myGif->start();

    QPoint p = Scene::getPlacePostion(x, y);    //获取坐标位置
    aPlant->setGeometry(p.x()-modeSize.width()/2, p.y()-modeSize.height()/2, modeSize.width(), modeSize.height());
    aPlant->show();

}

void Plants::plantInit(int hp, int atk, int speed, int range, int cooling, int cost)   //植物初始化
{
    this->hp = hp;
    this->atk = atk;
    this->speed = speed;
    this->range = range;
    this->cooling = cooling;
    this->cost = cost;
}


void Plants::fight()
{

}

void Plants::aFgiht()
{

}

void Plants::injured()
{

}

Plants::~Plants()
{

}

/*******************************************************************************************
                  豌豆射手

********************************************************************************************/
PeaShooter::PeaShooter(MainWindow *parent)
{
    this->myWindow = parent;
    this->plantInit(300, 20, 1400, 1, 7500, 100);
    this->fightState = 0;
    this->modeSize = QSize(71, 71);
    this->path = QString("../graphics/Plants/Peashooter/");
    this->pathBullet = new QMovie("../graphics/Bullets/Pea0.gif");
    this->pathExplosion = new QMovie("../graphics/Bullets/PeaExplosion.gif");
    fight();    //开启攻击
}

void PeaShooter::fight()        //植物攻击
{

    QTimer *timer = new QTimer(this);   //创建计时器
    timer->start(1400);                 //计时器1400ms刷新一次
    // 生产一个子弹
    connect(timer, &QTimer::timeout, [=](){
        if (fightState && !Zombies::ifEmptyInALine(this->postion.y()))
        {
            //发射豌豆 biubiubiu
            Bullets::addABullet(myWindow, postion.y(), postion.x(), atk);
        }
    });
}

void PeaShooter::aFgiht()       //一次攻击特效
{

}

void PeaShooter::injured()
{

}

PeaShooter::~PeaShooter()
{

}

/*******************************************************************************************
                  向日葵

********************************************************************************************/
SunFlower::SunFlower(MainWindow *parent)
{
    this->myWindow = parent;
    this->plantInit(100, 20, 1400, 1, 7500, 100);
    this->modeSize = QSize(71, 71);
    this->path = QString("../graphics/Plants/SunFlower/SunFlower_");
}

void SunFlower::fight()
{

}

void SunFlower::injured()
{

}

SunFlower::~SunFlower()
{

}
/*******************************************************************************************
                  坚果墙

********************************************************************************************/
WallNut::WallNut(MainWindow *parent)
{
    this->myWindow = parent;
    this->plantInit(100, 20, 1400, 1, 7500, 100);
    this->modeSize = QSize(65, 73);
    this->path = QString("../graphics/Plants/WallNut/WallNut/WallNut_");
}

void WallNut::fight()
{

}

void WallNut::injured()
{

}

WallNut::~WallNut()
{

}
/*******************************************************************************************
                  樱桃炸弹

********************************************************************************************/
CherryBomb::CherryBomb(MainWindow *parent)
{
    this->myWindow = parent;
    this->plantInit(100, 20, 1400, 1, 7500, 100);
    this->modeSize = QSize(100, 66);
    this->path = QString("../graphics/Plants/CherryBomb/CherryBomb_");
}

void CherryBomb::fight()
{

}

void CherryBomb::injured()
{

}

CherryBomb::~CherryBomb()
{

}
/*******************************************************************************************
                  倭瓜

********************************************************************************************/

Squash::Squash(MainWindow *parent)
{
    this->myWindow = parent;
    this->plantInit(100, 20, 1400, 1, 7500, 100);
    this->modeSize = QSize(90, 90);
    this->path = QString("../graphics/Plants/Squash/Squash/Squash_");
}

void Squash::fight()
{

}

void Squash::injured()
{

}

Squash::~Squash()
{

}

/*******************************************************************************************
                  土豆地雷

********************************************************************************************/

PotatoMine::PotatoMine(MainWindow *parent)
{
    this->myWindow = parent;
    this->plantInit(100, 20, 1400, 1, 7500, 100);
    this->modeSize = QSize(75, 55);
    this->path = QString("../graphics/Plants/PotatoMine/PotatoMineInit/PotatoMineInit_");
}

void PotatoMine::fight()
{

}

void PotatoMine::injured()
{

}

PotatoMine::~PotatoMine()
{

}

/*******************************************************************************************
                  冰豌豆射手

********************************************************************************************/

SnowPea::SnowPea(MainWindow *parent)
{
    this->myWindow = parent;
    this->plantInit(100, 20, 1400, 1, 7500, 100);
    this->modeSize = QSize(71, 71);
    this->fightState = 0;
    this->path = QString("../graphics/Plants/SnowPea/SnowPea_");
    fight();
}

void SnowPea::fight()
{
    QTimer *timer = new QTimer(this);   //创建计时器
    timer->start(1400);                 //计时器1400ms刷新一次

    connect(timer, &QTimer::timeout, [=](){if (fightState) this->aFgiht();});

}


void SnowPea::aFgiht()       //一次攻击特效
{
    Action *action = new Action(myWindow);
    QLabel *bullet = new QLabel(myWindow);
    bullet->setPixmap(QPixmap("../graphics/Bullets/PeaIce/PeaIce_0.png"));
    bullet->setGeometry(postion.x()*82+120 ,postion.y()*100+90, 56, 34);
    bullet->show();
    bullet->raise();
    bullet->setMouseTracking(true);
    action->widgetMove(bullet,1000,0,3000);     //发射豌豆 biubiubiu

    connect(action, &Action::OutOfMap, [=](){
        delete bullet;
        delete action;
    });
}


void SnowPea::injured()
{

}

SnowPea::~SnowPea()
{

}

/*******************************************************************************************
                  食人花

********************************************************************************************/

Chomper::Chomper(MainWindow *parent)
{
    this->myWindow = parent;
    this->plantInit(100, 20, 1400, 1, 7500, 100);
    this->modeSize = QSize(110, 100);
    this->path = QString("../graphics/Plants/Chomper/Chomper/Chomper_");
}

void Chomper::fight()
{

}

void Chomper::injured()
{

}

Chomper::~Chomper()
{

}

/*******************************************************************************************
                  豌豆爸爸

********************************************************************************************/

RepeaterPea::RepeaterPea(MainWindow *parent)
{
    this->myWindow = parent;
    this->plantInit(100, 20, 1400, 1, 7500, 100);
    this->modeSize = QSize(71, 71);
    this->pathBullet = new QMovie("../graphics/Bullets/Pea0.gif");
    this->pathExplosion = new QMovie("../graphics/Bullets/PeaExplosion.gif");
    this->path = QString("../graphics/Plants/Repeater/");
    fight();    //开启攻击
}

void RepeaterPea::fight()
{    
    QTimer *timer0 = new QTimer(this);      //创建计时器0
    QTimer *timer1 = new QTimer(this);      //创建计时器1
    timer0->start(1400);                 //计时器1400ms刷新一次

    connect(timer0, &QTimer::timeout, [=](){
        if (fightState) this->aFgiht();
        timer1->start(200);
        qDebug() << "-----BB qian-----";

    });
    connect(timer1, &QTimer::timeout, [=](){
        timer1->stop();
        if (fightState) this->aFgiht();
        qDebug() << "-----BB hou------";
    });
}

RepeaterPea::~RepeaterPea()
{

}










































































































































