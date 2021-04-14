#include "bullets.h"


BulletsVector Bullets::bulletsVector[5] = {};


Bullets::Bullets(MainWindow *parent, int line, int xPos, int atk)
    : myWindow(parent), line(line), atk(atk)
{
    this->pathBullet = new QMovie("../graphics/Bullets/Pea0.gif");
    this->pathExplosion = new QMovie(" ../graphics/Bullets/PeaExplosion.gif");
    this->action = new Action(myWindow);
    this->bullet = new QLabel(myWindow);

    bullet->setMovie(pathBullet);
    bullet->setMouseTracking(true);
    bullet->setScaledContents(true);
    pathBullet->start();

    bullet->setGeometry(xPos*82+100, line*100+90, 56, 34);  
    bullet->show();
    bullet->raise();
    action->widgetMove(bullet,1000,0,3000,line);
}


void Bullets::fight()
{

    action->blockSignals(true);
    bullet->hide();
    Action *action_boom = new Action();
    QLabel *label_boom = new QLabel(myWindow);
    label_boom->setMovie(pathExplosion);
    pathExplosion->start();
    label_boom->setGeometry(action->xPox(), line*100+90, 52, 46);
    label_boom->show();
    bullet->setMouseTracking(true);
    action->widgetMove(label_boom, 0, 0, 200);
    connect(action, &Action::moveFinish, [=](){
        delete action_boom;
        delete label_boom;
        qDebug() << "explose finish";
    });
}


Bullets::~Bullets()
{
    qDebug() << "bullet delete";

    delete action;
    delete bullet;

    delete myGif;
    delete pathBullet;
    delete pathExplosion;
}



// static
void Bullets::addABullet(MainWindow *parent, int line, int xPos, int atk)
{
    Bullets *b = new Bullets(parent, line, xPos, atk);
    BulletsVector &bv = bulletsVector[line];
    BulletsVector::iterator i;
    //qDebug() << "add b xpos:" << b->action->xPox();
    // 按从大到小排序
    for (i=bv.begin(); i!=bv.end(); i++)
    {
        //qDebug() << "b xpos:" << (*i)->action->xPox();
        if ((*i)->action->xPox() < b->action->xPox())
            break;
    }
    // 添加子弹
    bv.insert(i, b);

    for (i=bv.begin(); i!=bv.end(); i++)
    {
        qDebug() << "b xpos:" << (*i)->action->xPox();

    }
    qDebug();

}

int Bullets::collsionDetection(int line, int xPos)
{
    int allAtk = 0;
    BulletsVector &bv = bulletsVector[line];
    BulletsVector::iterator i;

    for (i=bv.begin(); i!=bv.end(); i++)
    {
        // 打不到僵尸了
        if ((*i)->action->xPox() < xPos)
            break;

        // 打到僵尸，计算伤害
        allAtk += (*i)->atk;
        (*i)->fight();
        (*i)->deleteLater();
        bv.erase(i);
    }

    return allAtk;
}

void Bullets::outOfMapDetection(int line)
{
    BulletsVector &bv = bulletsVector[line];
    BulletsVector::iterator i;

    for (i=bv.begin(); i!=bv.end(); i++)
    {
        // 超出地图

        if ((*i)->action->xPox() > 850)
        {
            qDebug() << "out of map";
            delete (*i);
            bv.erase(i);
        }
        else    //后面的都不会超了
            break;
    }
}
