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
    explicit Bullets(MainWindow *parent = nullptr, int line=0, int xPos=0, int injury=0);
    ~Bullets();
    virtual void fight();

    static void addABullet(MainWindow *parent, int line, int xPos, int atk);
    static int collsionDetection(int line, int xPos);
    static void outOfMapDetection(void);

protected:
    MainWindow *myWindow;
    QString path;
    Action *action;
    QLabel *bullet;
    QMovie *pathBullet;
    QMovie *pathExplosion;

    int line;
    int atk;

    static BulletsVector bulletsVector[5];


};

#endif // BULLET_H
