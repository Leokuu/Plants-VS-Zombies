#include "card.h"
#include <QPushButton>
#include <QDebug>
#include <QObject>
#include <QMainWindow>

Card::Card(MainWindow *parent)
{
    Card::myWindow = parent;
    Card::loadCard();
    Card::chooserNumber = 0;
    int i; for (i=0; i<chooserMax; i++) chooserState[i]=-1; //初始化空
}

//加载植物卡片
void Card::loadCard()
{
    int i;

    path[0] = QString("%1card_peashooter.png").arg(path0);      //豌豆射手
    path[1] = QString("%1card_sunflower.png").arg(path0);       //向日葵
    path[2] = QString("%1card_wallnut.png").arg(path0);         //坚果墙
    path[3] = QString("%1card_cherrybomb.png").arg(path0);      //樱桃炸弹
    path[4] = QString("%1card_squash.png").arg(path0);          //倭瓜
    path[5] = QString("%1card_potatomine.png").arg(path0);      //土豆地雷
    path[6] = QString("%1card_snowpea.png").arg(path0);         //冰豌豆射手
    path[7] = QString("%1card_chomper.png").arg(path0);         //食人花
    path[8] = QString("%1card_repeaterpea.png").arg(path0);     //豌豆爸爸


    for (i=0; i<cardNumber; i++)
    {
        cardButton[i] = new QPushButton(myWindow);           //创建按钮
        cardButton[i]->setIcon(QIcon(path[i]));                    //设置图表
        cardButton[i]->setIconSize(QSize(cardWidth, CardHeight));
        cardXY[i] = QSize(25+i*(cardWidth+clearance), 126+i/8*(CardHeight+clearance));
        cardButton[i]->setGeometry(cardXY[i].width(), cardXY[i].height(), cardWidth, CardHeight);     //设置位置，大小
        cardButton[i]->hide();
    }
}

//准备战斗时选择上场的植物
void Card::cardShow()
{
    int i;
    for (i=0; i<cardNumber; i++)
    {
        //置顶并显示
        cardButton[i]->raise();     //卡片置顶
        cardButton[i]->show();      //显示卡片
        cardState[i] = -1;           //状态为1，即在全体植物栏
    }

    for (i=0; i<cardNumber; i++)
    {
        myAction[i] = new Action();    //创建动画对象
        QObject::connect(cardButton[i], &QPushButton::clicked, [=](){   //建立起多个连接

            cardButton[i]->blockSignals(true);      //信号阻塞防止再点击

            if (cardState[i] == -1)         //卡片在哪里
            {           //在下面，全体植物栏
                int j=-1; while (chooserState[++j]!=-1);     //找到空位
                cardState[i] = j;           //移去战斗植物栏
                myAction[i]->widgetLocate(cardButton[i], 82+j*(cardWidth+clearance+1), 7, cardMoveTime);
                chooserState[j] = i;        //记录当前位置的植物
                chooserNumber++;            //已选择卡牌数量
                if (chooserNumber == chooserMax) emit CanStartFighting();
            }
            else
            {           //在上面，战斗植物栏
                if (chooserNumber == chooserMax) emit CannotStartFighting();
                myAction[i]->widgetLocate(cardButton[i], cardXY[i].width(), cardXY[i].height(), cardMoveTime);
                chooserState[cardState[i]] = -1;    //清除当前卡槽植物
                cardState[i] = -1;          //移去全体植物栏
                chooserNumber--;
            }


            cardButton[i]->blockSignals(false);      //信号阻塞解除，允许点击

        });

    }

}


void Card::fightingMode()
{
    int i;
    for (i=0; i<chooserMax; i++)
    {
        connect(cardButton[i], &QPushButton::clicked, [=](){} );
    }
}

Card::~Card()
{
    qDebug()<< "card end";
}


















