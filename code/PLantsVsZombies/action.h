#ifndef ACTION_H
#define ACTION_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QTimer>
#include "mainwindow.h"
#include "card.h"

const int timerFrequency = 5;

class MainWindow;   //声明 Mainwindow 类

class Action : public QWidget
{
    Q_OBJECT

public:
    explicit Action(MainWindow *parent = nullptr);
    void totalMove(int x, int y, int time);
    //控件移动
    void widgetMove(QLabel *label,int x, int y, int time);
    void widgetMove(QPushButton *button, int x, int y, int time);
    //控件位置重置
    void widgetLocate(QLabel *label,int x, int y, int time);
    void widgetLocate(QPushButton *label,int x, int y, int time);
    //控件跟随鼠标
    void widgetMouse(QPushButton *button, QLabel *label);
    //植物左右晃
    void plantWave(QLabel *label, QString path,int frameNum);

public slots:
    void move();

signals:
    void moveFinish();  //移动结束信号
    void FinishPlace(QPoint); //放置植物信号
    void DonotPlace();    //取消放置信号

private:
    QTimer *timer;
    QWidget *myWidget;
    MainWindow *mywindow;
    int startX;         //初始X轴位置
    int startY;         //初始Y轴位置
    int endX;           //结束X轴位置
    int endY;           //结束Y轴位置
    int moveNum;        //移动次数
    float preX;         //一次移动X轴距离
    float preY;         //一次移动Y轴距离
    int n;              //计数
    void plantsActionLoad();     //加载动画
};

#endif // ACTION_H
