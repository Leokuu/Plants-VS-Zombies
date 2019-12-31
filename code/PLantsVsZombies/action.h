#ifndef ACTION_H
#define ACTION_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QTimer>
#include "mainwindow.h"

const int timerFrequency = 2;

class MainWindow;   //声明 Mainwindow 类

class Action : public QObject
{
    Q_OBJECT

public:
    explicit Action();
    void totalMove(int x, int y, int time);
    //控件移动
    void widgetMove(QLabel *label,int x, int y, int time);
    void widgetMove(QPushButton *button, int x, int y, int time);
    //控件位置重置
    void widgetLocate(QLabel *label,int x, int y, int time);
    void widgetLocate(QPushButton *label,int x, int y, int time);

public slots:
    void move();

signals:
    //移动结束信号
    void moveFinish();

private:
    QTimer *timer;
    QWidget *myWidget;
    int startX;       //初始X轴位置
    int startY;       //初始Y轴位置
    int endX;           //结束X轴位置
    int endY;           //结束Y轴位置
    int moveNum;        //移动次数
    float preX;         //一次移动X轴距离
    float preY;         //一次移动Y轴距离
    int n;              //计数
};

#endif // ACTION_H
