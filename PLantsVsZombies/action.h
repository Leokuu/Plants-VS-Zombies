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

const int timerFrequency = 15;      //60Hz 刷新率

class MainWindow;   //声明 Mainwindow 类

class Action : public QWidget
{
    Q_OBJECT

public:
    explicit Action(MainWindow *parent = nullptr);
    void totalMove(int x, int y, int time);
    //控件移动
    void widgetMove(QLabel *label,int x, int y, int time, int pea=0);
    void widgetMove(QPushButton *button, int x, int y, int time);
    //控件位置重置
    void widgetLocate(QLabel *label,int x, int y, int time);
    void widgetLocate(QPushButton *label,int x, int y, int time);
    //控件跟随鼠标
    void widgetMouse(QPushButton *button, QLabel *label, QSize size);
    //左右晃
    //void plantWave(QLabel *label, QString path,int frameNum);
    //void zombieWave(QLabel *label, QString path, int frameNum, int time);
    //攻击
    //void peaFight(QLabel *label);
    int xPox(){return this->xPos;}

public slots:
    void move();

signals:
    void moveFinish();          //移动结束信号
    void FinishPlace(QPoint);   //放置植物信号
    void DonotPlace();          //取消放置信号
    void OutOfMap();            //超出地图
    void peaPos(int);           //子弹位置

private:
    QTimer *timer;
    QWidget *myWidget;
    MainWindow *mywindow;
    int startX;         //初始X轴位置
    int startY;         //初始Y轴位置
    int endX;           //结束X轴位置
    int endY;           //结束Y轴位置
    int xPos;           //实时X坐标
    int yPos;           //实时Y坐标
    int moveNum;        //移动次数
    float preX;         //一次移动X轴距离
    float preY;         //一次移动Y轴距离
    int n;              //计数
    int pea;            //是否获取豌豆坐标
    void plantsActionLoad();     //加载动画
};

#endif // ACTION_H
