#ifndef BULLET_H
#define BULLET_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "mainwindow.h"

class Bullets;

typedef QVector<Bullets *> BulletsVector;

class Bullets : public QWidget
{
    Q_OBJECT

public:
    explicit Bullets(MainWindow *parent = nullptr, int line=0, int xPos=0);
    ~Bullets();
    virtual void fight(int);

    static void addABullet(MainWindow *parent, int line, int xPos);

protected:
    MainWindow *myWindow;
    QString path;
    Action *action;
    QLabel *bullet;
    QMovie *myGif;
    QMovie *pathBullet;
    QMovie *pathExplosion;

    int line;

    static BulletsVector bulletsVector[5];


};

#endif // BULLET_H
