#include "bullets.h"


BulletsVector Bullets::bulletsVector[5] = {};


Bullets::Bullets(MainWindow *parent, int line, int xPos)
    : myWindow(parent), line(line)
{
    this->pathBullet = new QMovie("../../graphics/Bullets/Pea0.gif");
    this->pathExplosion = new QMovie("../../graphics/Bullets/PeaExplosion.gif");

    Action *action = new Action(myWindow);
    QLabel *bullet = new QLabel(myWindow);
    bullet->setMovie(pathBullet);
    pathBullet->start();
    bullet->setGeometry(xPos*82+100, line*100+90, 56, 34);
    bullet->show();
    bullet->raise();
    bullet->setMouseTracking(true);
    action->widgetMove(bullet,1000,0,3000,line.y());

}

Bullets::~Bullets()
{

}



void Bullets::create()
{

}

void Bullets::addABullet(MainWindow *parent, int line, int xPos)
{
    Bullets *b = new Bullets(parent, line, xPos);
    Bullets::bulletsVector[line].push_back(b);
}
