#include "mainwindow.h"
#include "scene.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QMainWindow::setMaximumSize(windowWidth, windowHeight);
    QMainWindow::setMinimumSize(windowWidth, windowHeight);     //设定大小


    MainWindow::myscene = new Scene(this);
    myscene->mapDaytime();
}

MainWindow::~MainWindow()
{

}
