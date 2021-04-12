#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "scene.h"
#include <QWidget>
#include <QDebug>
#include <QMouseEvent>

#define windowWidth  850
#define windowHeight 600

class Scene;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QPoint getMousePostion() {return this->mousePostion;}        //获取鼠标位置
    Scene *myscene;

signals:
    void leftPress();
    void rightPress();

private:
    QPoint mousePostion;        //鼠标位置

protected:
    void mouseMoveEvent(QMouseEvent *e);
    void mousePressEvent(QMouseEvent *e);
};

#endif // MAINWINDOW_H
