#ifndef CARD_H
#define CARD_H

#include <QMainWindow>
#include <QObject>
#include <QPushButton>
#include "mainwindow.h"
#include "action.h"

class MainWindow;       //声明 MainWidow类
class Action;           //声明 动画类

#define cardWidth  50       //卡片长宽65*90
#define CardHeight 70
#define cardMoveTime 150    //卡牌移动时间
#define clearance  3        //间隔
#define chooserMax 8        //上场植物数量
#define cardNumber 9        //卡牌数量

class Card : public QWidget
{
    Q_OBJECT

public:
    explicit Card(MainWindow *parent = nullptr);
    ~Card();
    void cardShow();        //卡片显示
    void loadCard();        //准备模式，加载卡片
    void fightingMode();    //战斗模式
    void setButtonState(int n,int state);   //0隐藏  1显示  2冷却
    int  getChooserPlant(int n) {return chooserPlant[n];}
    int  getCardState(int n) {return cardState[n];}
    void hideAButton(int n) {cardButton[n]->hide();}
    //static QSize getChooserXY(int n){return QSize(82+n*(cardWidth+clearance+1), 7);}   //返回坐标

signals:
    void CanStartFighting();        //加载开始战斗按钮
    void CannotStartFighting();     //隐藏开始战斗按钮
    void PlcaePlant(int);           //放置植物  connect in Scene.cpp

private:
    MainWindow *myWindow;                   //主窗口地址
    QPushButton *cardButton[cardNumber];    //按钮数组
    QSize cardXY[cardNumber];               //按钮初始坐标
    Action *myAction[cardNumber];           //动画类数组
    QString path[cardNumber];               //图片地址数组
    QString path0 = QString("../graphics/Cards/");   //卡片文件夹地址
    int cardState[cardNumber];              //卡片状态数组
    int chooserNumber;                      //当前卡牌槽卡片数量
    int chooserPlant[chooserMax];           //卡牌槽对应植物
};



#endif // CARD_H

/*   card对应表
 * 0  豌豆射手
 * 1  向日葵
 * 2  坚果墙
 * 3  樱桃炸弹
 * 4  冰豌豆射手
 * 5  倭瓜
 * 6  食人花
 */

