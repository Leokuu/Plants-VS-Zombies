#include "bullets.h"


BulletsVector Bullets::bulletsVector[5] = {};


Bullets::Bullets(MainWindow *parent, int line, int xPos)
    : myWindow(parent), line(line)
{
    this->pathBullet = new QMovie("../../graphics/Bullets/Pea0.gif");
    this->pathExplosion = new QMovie("../../graphics/Bullets/PeaExplosion.gif");

    this->action = new Action(myWindow);
    this->bullet = new QLabel(myWindow);
    bullet->setMovie(pathBullet);
    pathBullet->start();
    bullet->setGeometry(xPos*82+100, line*100+90, 56, 34);
    bullet->show();
    bullet->raise();
    bullet->setMouseTracking(true);
    action->widgetMove(bullet,1000,0,3000,line);

    connect(action, &Action::OutOfMap, [=](){   //到点清除
        //bullet->hide();
        delete action;
        delete bullet;
    });
}


void Bullets::fight(int peaPosX)
{

    action->blockSignals(true);
    bullet->hide();
    Action *action_boom = new Action();
    QLabel *label_boom = new QLabel(myWindow);
    label_boom->setMovie(pathExplosion);
    pathExplosion->start();
    label_boom->setGeometry(peaPosX, line*100+90, 52, 46);
    label_boom->show();
    bullet->setMouseTracking(true);
    action->widgetMove(label_boom, 0, 0, 200);
    connect(action, &Action::moveFinish, [=](){
        delete action_boom;
        delete label_boom;
    });
}

Bullets::~Bullets()
{

    delete action;
    delete bullet;

    delete myGif;
    delete pathBullet;
    delete pathExplosion;
}



// static
void Bullets::addABullet(MainWindow *parent, int line, int xPos)
{
    Bullets *b = new Bullets(parent, line, xPos);
    Bullets::bulletsVector[line].push_back(b);
}
