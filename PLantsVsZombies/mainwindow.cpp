#include "mainwindow.h"
#include "scene.h"
#include <QMouseEvent>

QPoint Scene::placePostion[9][5];

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    this->setMaximumSize(windowWidth, windowHeight);
    this->setMinimumSize(windowWidth, windowHeight);     //设定大小
    this->setMouseTracking(true);       //相应鼠标位置

    this->myscene = new Scene(this);
    myscene->mapDaytime();
}

void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    this->mousePostion = e->pos();
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    if (e->button() == Qt::LeftButton)
    {
        emit leftPress();
        qDebug() << "----left----";
    }
    if (e->button() == Qt::RightButton) emit rightPress();
}

MainWindow::~MainWindow()
{
    delete this;
    qDebug() << "ByeBye!";
}

