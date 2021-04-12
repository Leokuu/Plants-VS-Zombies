#include "action.h"
#include "mainwindow.h"
#include "scene.h"
#include <QTimer>
#include <QObject>
#include <QDebug>
#include <QWidget>
#include <QMouseEvent>
#include <QGraphicsOpacityEffect>

Action::Action(MainWindow *parent)
{
    this->mywindow = parent;
    this->timer = new QTimer(this);   //创建计时器
    this->timer->setTimerType(Qt::PreciseTimer);
    this->timer->start(timerFrequency);      //计时器刷新频率 10Hz
    this->n = 0;
}

void Action::move()
{
    myWidget->move( (int)(startX+preX* (++n)), (int)(startY+ preY* n));
    //qDebug() << "In move "<<myWidget->pos().x() << " " <<myWidget->pos().y();
    if (pea) emit peaPos(myWidget->x());
    if (myWidget->pos().x() > 850)
    {
        //qDebug() << "---preX:" << preX << "--preY:" << preY << "---" <<n;
        emit OutOfMap();
        disconnect(timer, &QTimer::timeout, this, 0);   //断开连接
    }
    if (n==moveNum) {      //移动完成
        this->n = 0;
        disconnect(timer, &QTimer::timeout, this, 0);   //断开连接
        myWidget->move(endX, endY);                     //修正误差
        //qDebug() << "move dowm "<<myWidget->pos().x() << " " <<myWidget->pos().y();
        //qDebug() << "";
        emit moveFinish();
    }
}

void Action::totalMove(int x, int y, int time)
{
    this->startX = myWidget->pos().x();               //起始坐标X
    this->startY = myWidget->pos().y();               //起始坐标Y
    this->endX = x;                                   //结束坐标X
    this->endY = y;                                   //结束坐标Y
    this->moveNum = time / timerFrequency;            //移动次数
    this->preX = (float)(endX - startX) / moveNum;    //单次移动X轴
    this->preY = (float)(endY - startY) / moveNum;    //单次移动Y轴
    this->n = 0;                                      //计数清零
    //连接移动信号槽
    connect(timer, &QTimer::timeout, this, &this->move);

}


//根据方向移动
void Action::widgetMove(QLabel *label, int x, int y, int time, int pea)
{
    this->myWidget = (QWidget*) label;
    this->totalMove(x+myWidget->pos().x(), y+myWidget->pos().y(), time);
    this->pea = pea;
}

void Action::widgetMove(QPushButton *button, int x, int y, int time)
{    
    this->myWidget = (QWidget*) button;
    this->totalMove(x+myWidget->pos().x(), y+myWidget->pos().y(), time);
}

//根据结束位置移动
void Action::widgetLocate(QLabel *label, int x, int y, int time)
{    
    this->myWidget = (QWidget*) label;
    this->totalMove(x, y, time);
}

void Action::widgetLocate(QPushButton *button, int x, int y, int time)
{

    this->myWidget = (QWidget*) button;
    this->totalMove(x, y, time);
}

//控件跟随鼠标
#define mouseXY  mywindow->getMousePostion()
void Action::widgetMouse(QPushButton *button, QLabel *label, QSize size)
{
    //放置位置显示标志
    QGraphicsOpacityEffect *o = new QGraphicsOpacityEffect;
    o->setOpacity(0.5);             //半透明
    label->setGraphicsEffect(o);

    QPoint p;
    button->raise();
    this->startX = button->pos().x();                 //中心坐标X
    this->startY = button->pos().y();                 //中心坐标Y

    connect(timer, &QTimer::timeout, [=]()mutable{             //跟随鼠标移动
        button->move(mouseXY.x()-25, mouseXY.y()-35);   //植物位于鼠标中心
        p = Scene::getPlacePostion((mouseXY.x()-75)/mapPreX, (mouseXY.y()-90)/mapPreY);
        label->move(p.x()-size.width()/2, p.y()-size.height()/2);
        if (mywindow->myscene->getArrayPlants((mouseXY.x()-75)/mapPreX, (mouseXY.y()-90)/mapPreY)==1){
            label->hide();
            button->blockSignals(true);
        }
        else {
            label->show();
            button->blockSignals(false);
        }
    });

    connect(mywindow, &MainWindow::rightPress, [=](){   //右键取消放置
        disconnect(timer, &QTimer::timeout, 0, 0);
        label->hide();
        emit DonotPlace();
    });

    connect(button, &QPushButton::pressed, [=](){       //左键确认放置植物
        disconnect(timer, &QTimer::timeout, 0, 0);
        label->hide();
        emit FinishPlace(mouseXY);
    });
}










