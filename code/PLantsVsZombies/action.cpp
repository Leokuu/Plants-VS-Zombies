#include "action.h"
#include "mainwindow.h"
#include <QTimer>
#include <QObject>
#include <QDebug>
#include <QWidget>

Action::Action()
{
    Action::timer = new QTimer(this);   //创建计时器
    Action::timer->start(timerFrequency);      //计时器16ms刷新一次，即60Hz
    Action::n = 0;
}

void Action::move()
{
    myWidget->move( (int)(startX+preX* ++n), (int)(startY+ preY* n));
   // qDebug() << "In move "<<myWidget->pos().x() << " " <<myWidget->pos().y();
    if (n==moveNum) {      //移动完成
        disconnect(timer, &QTimer::timeout, this, 0);   //断开连接
        myWidget->move(endX, endY);                     //修正误差
        //qDebug() << "move dowm "<<myWidget->pos().x() << " " <<myWidget->pos().y();
        //qDebug() << "";
        emit moveFinish();
    }
}

void Action::totalMove(int x, int y, int time)
{
    Action::startX = myWidget->pos().x();               //起始坐标X
    Action::startY = myWidget->pos().y();               //起始坐标Y
    Action::endX = x;                                   //结束坐标X
    Action::endY = y;                                   //结束坐标Y
    Action::moveNum = time / timerFrequency;            //移动次数
    Action::preX = (float)(endX - startX) / moveNum;    //单次移动X轴
    Action::preY = (float)(endY - startY) / moveNum;    //单次移动Y轴
    Action::n = 0;                                      //计数清零
    //qDebug() << "start location"<< startX << startY << moveNum;
    //qDebug() << "end location  "<< x << y;
    //qDebug() << "pre move      "<< QString("%1 %2").arg(preX).arg(preY);
    //连接移动信号槽
    connect(timer, &QTimer::timeout, this, &Action::move);

}


//根据方向移动
void Action::widgetMove(QLabel *label, int x, int y, int time)
{
    Action::myWidget = (QWidget*) label;
    Action::totalMove(x+myWidget->pos().x(), y+myWidget->pos().y(), time);
}

void Action::widgetMove(QPushButton *button, int x, int y, int time)
{    
    Action::myWidget = (QWidget*) button;
    Action::totalMove(x+myWidget->pos().x(), y+myWidget->pos().y(), time);
}

//根据结束位置移动
void Action::widgetLocate(QLabel *label, int x, int y, int time)
{    
    Action::myWidget = (QWidget*) label;
    Action::totalMove(x, y, time);
}

void Action::widgetLocate(QPushButton *button, int x, int y, int time)
{

    Action::myWidget = (QWidget*) button;
    Action::totalMove(x, y, time);
}





