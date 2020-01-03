#include "plants.h"
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QTimer>
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
    button->setIcon(QIcon(QString("%1%2.png").arg(path).arg(0)));
    button->setIconSize(QSize(71,71));
    button->resize(71,71);
    button->show();
    button->setMouseTracking(true);

    QLabel *label = new QLabel(myWindow);
    label->setPixmap(QPixmap(QString("%1%2.png").arg(path).arg(0)));
    label->resize(71,71);
    label->show();

    myWindow->setCursor(Qt::BlankCursor);           //隐藏鼠标
    Action *plantAction = new Action(myWindow);     //创建动画
    plantAction->widgetMouse(button, label);        //跟随鼠标移动

    connect(plantAction, &Action::FinishPlace, [=](QPoint postion){     //放置一个植物
        disconnect(plantAction, 0, 0, 0);           //断开连接
        myWindow->setCursor(Qt::ArrowCursor);       //显示鼠标
        button->hide();
        QPoint p = QPoint( (postion.x()-75)/mapPreX, (postion.y()-90)/mapPreY );
        aPlantAdd(p.x(), p.y());
        emit placePostion( p.x(), p.y() );
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
    QLabel *aPlant = new QLabel(myWindow);
    aPlant->setPixmap(QPixmap(path));

    QPoint p = Scene::getPlacePostion(x, y);    //获取坐标位置
    aPlant->setGeometry(p.x(), p.y(), 71, 71);
    aPlant->show();

    Action *action = new Action();              //创建动画
    action->plantWave(aPlant, path ,frameNum);  //动起来
}

void Plants::plantInit(int frame, int hp, int atk, int speed,int range, int cooling, int cost)   //植物初始化
{
    this->frameNum = frame;
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
    this->plantInit(13, 100, 20, 1400, 1, 7500, 100);
    this->path = QString("../../graphics/Plants/Peashooter/Peashooter_");
}

void PeaShooter::fight()
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
    this->plantInit(18, 100, 20, 1400, 1, 7500, 100);
    this->path = QString("../../graphics/Plants/SunFlower/SunFlower_");
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
    this->plantInit(16, 100, 20, 1400, 1, 7500, 100);
    this->path = QString("../../graphics/Plants/WallNut/WallNut/WallNut_");
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
    this->plantInit(7, 100, 20, 1400, 1, 7500, 100);
    this->path = QString("../../graphics/Plants/CherryBomb/CherryBomb_");
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
    this->plantInit(17, 100, 20, 1400, 1, 7500, 100);
    this->path = QString("../../graphics/Plants/Squash/Squash/Squash_");
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
    this->plantInit(8, 100, 20, 1400, 1, 7500, 100);
    this->path = QString("../../graphics/Plants/PotatoMine/PotatoMine/PotatoMine_");
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
    this->plantInit(15, 100, 20, 1400, 1, 7500, 100);
    this->path = QString("../../graphics/Plants/SnowPea/SnowPea_");
}

void SnowPea::fight()
{

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
    this->plantInit(13, 100, 20, 1400, 1, 7500, 100);
    this->path = QString("../../graphics/Plants/Chomper/Chomper/Chomper_");
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
    this->plantInit(13, 100, 20, 1400, 1, 7500, 100);
    this->path = QString("../../graphics/Plants/RepeaterPea/RepeaterPea_");
}

void RepeaterPea::fight()
{

}

void RepeaterPea::injured()
{

}

RepeaterPea::~RepeaterPea()
{

}










































































































































