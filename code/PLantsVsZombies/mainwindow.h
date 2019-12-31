#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "scene.h"
#include <QDebug>

#define windowWidth  850
#define windowHeight 600

class Scene;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void check() {qDebug() << "success check";}

private:
    Scene *myscene;
};

#endif // MAINWINDOW_H
