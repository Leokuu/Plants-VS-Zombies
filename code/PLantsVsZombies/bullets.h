#ifndef BULLET_H
#define BULLET_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "mainwindow.h"

typedef QVector<Bullets *> BulletsVector;

class Bullets : public QWidget
{
    Q_OBJECT

public:
    explicit Bullets(MainWindow *parent = nullptr, int line=0, int xPos=0);
    ~Bullets();
    virtual void create();

    static void addABullet(MainWindow *parent, int line);

protected:
    MainWindow *myWindow;
    QString path;
    Action *action;
    QMovie *myGif;
    QMovie *pathBullet;
    QMovie *pathExplosion;
    int line;

    static BulletsVector bulletsVector[5];


};

#endif // BULLET_H
