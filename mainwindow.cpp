#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
#include<QtGlobal>
#include <QPoint>
QList<tab *>m_posList;
QButtonGroup *MainWindow::m_bg=NULL;
int m1 =0;
int n1 =0;
int c=0;
int k1=1;
int k2=1;
extern  QList<int> numbersList;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    if(m_bg!=NULL)
    delete m_bg;
    m_bg=new QButtonGroup(this);
    ui->setupUi(this);
    ui->toolButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    ui->toolButton_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    ui->toolButton_3->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    ui->toolButton_3->setVisible(false);
    ui->textEdit->setVisible(false);
    ui->widget_2->setVisible(false);
    ui->pushButton_10->setVisible(false);
    ui->pushButton_2->setVisible(true);
    ui->pushButton_7->setVisible(false);
    ui->pushButton->setEnabled(false);
    ui->pushButton_10->setEnabled(false);
    time= QTime(0,0,0,0);
    szTime = time.toString("hh:mm:ss");
        ui->lcdNumber->display(szTime);

        pTimer=new QTimer;//首先创建一个定时器
           connect(pTimer,SIGNAL(timeout()),
                 this,SLOT(showTime()));//关联信号和槽函数,自定义的普通类不能使用
        connect(m_bg,SIGNAL(buttonClicked(int)),this,SLOT(isCorrect(int)));  //点击按钮　调用槽函数
}
void MainWindow::showTime()
{
  //  static QTime time = QTime(0,0,0,0);
    szTime =  time.toString("hh:mm:ss");
    ui->lcdNumber->display(szTime);
    time = time.addMSecs(1000);
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_2_clicked()
{
showFullScreen();
ui->pushButton_2->setVisible(false);
ui->pushButton_7->setVisible(true);
}
void MainWindow::on_pushButton_7_clicked()
{
    showNormal();
    ui->pushButton_2->setVisible(true);
    ui->pushButton_7->setVisible(false);
}
void MainWindow::on_pushButton_6_clicked()//自定义
{
    ui->widget_3->setVisible(false);
    ui->widget_2->setVisible(true);
}

void MainWindow::on_pushButton_8_clicked()
{
    ui->widget_3->setVisible(true);
    ui->widget_2->setVisible(false);
}
void MainWindow::yincang()
{
    ui->widget_3->setVisible(false);
    ui->widget_2->setVisible(false);
}
void MainWindow::on_pushButton_3_clicked()//8*8个雷
{
    ui->pushButton->setEnabled(true);
    ui->pushButton_10->setEnabled(true);
   yincang();
    anjian2(8,8,10);
    m1 =8;
    n1 =8;
}
void MainWindow::anjian1(int index1,int index2,int index3)//30*16按钮
{
  int  x=30;
  int  y=70;
  for(int j=0;j<index2;j++)
    {
    for(int i=0;i<index1;i++)
        {
      struct tab *tab1=new struct tab;
       tab1->Leibtn2=new QPushButton(this);
       tab1->Leibtn2->setGeometry(x+30,y,40,40);
       tab1->val=0;
       tab1->clickFlag=0;
       m_posList.append(tab1);
       tab1->Leibtn2->show();
       x=x+40;
     }
y=y+40;
x=30;
}
  boom().set_ray_btn(index1, index2,index3);
  for(int j=0;j<index1*index2;j++)
  m_bg->addButton(m_posList.at(j)->Leibtn2,j);
}
void MainWindow::anjian2(int index1,int index2,int index3)//8*8按钮
{
  int  x=100;
  int  y=80;
  for(int j=0;j<index2;j++)
    {
    for(int i=0;i<index1;i++)
        {
      struct tab *tab1=new struct tab;
       tab1->Leibtn2=new QPushButton(this);
       tab1->Leibtn2->setGeometry(x+100,y,80,80);
       tab1->val=0;
       tab1->clickFlag=0;
       m_posList.append(tab1);
       tab1->Leibtn2->show();
       x=x+80;
     }
y=y+80;
x=100;
}
  boom().set_ray_btn(index1, index2,index3);
  for(int j=0;j<index1*index2;j++)
  m_bg->addButton(m_posList.at(j)->Leibtn2,j);
}
void MainWindow::anjian3(int index1,int index2,int index3)//16*16按钮
{
  int  x=80;
  int  y=70;
  for(int j=0;j<index2;j++)
    {
    for(int i=0;i<index1;i++)
        {
      struct tab *tab1=new struct tab;
       tab1->Leibtn2=new QPushButton(this);
       tab1->Leibtn2->setGeometry(x+80,y,40,40);
       tab1->val=0;
       tab1->clickFlag=0;
       m_posList.append(tab1);
       tab1->Leibtn2->show();
       x=x+40;
     }
y=y+40;
x=80;
}
  boom().set_ray_btn(index1, index2,index3);
  for(int j=0;j<index1*index2;j++)
  m_bg->addButton(m_posList.at(j)->Leibtn2,j);
}
void MainWindow::isCorrect(int id)
{
    pTimer->start(1000);
    if( m_posList.at(id)->clickFlag != 3)
    {
    m_posList.at(id)->clickFlag=1;
    m_posList.at(id)->Leibtn2->setEnabled(false);
    if(m_posList.at(id)->val==0)
        spread(id);
    if(m_posList.at(id)->val==-1)
    {
           pTimer->stop();
           time= QTime(0,0,0,0);
           showTime();
        if(m1==8&& n1==8)
        {
        m_posList.at(id)->Leibtn2->setIcon(QPixmap("://image/9.png"));
        m_posList.at(id)->Leibtn2->setIconSize(QSize(80,80));
        }
        else
        {
            m_posList.at(id)->Leibtn2->setIcon(QPixmap("://image/9.png"));
            m_posList.at(id)->Leibtn2->setIconSize(QSize(40,40));
        }
        dispaly_ray(id);
    }
    if(m_posList.at(id)->val==1)
    {
    m_posList.at(id)->Leibtn2->setIcon(QPixmap("://image/1.png"));
    m_posList.at(id)->Leibtn2->setIconSize(QSize(80,80));
    }
     if(m_posList.at(id)->val==2)
     {
    m_posList.at(id)->Leibtn2->setIcon(QPixmap("://image/2.png"));
    m_posList.at(id)->Leibtn2->setIconSize(QSize(80,80));
     }
    if(m_posList.at(id)->val==3)
    {
    m_posList.at(id)->Leibtn2->setIcon(QPixmap("://image/3.png"));
    m_posList.at(id)->Leibtn2->setIconSize(QSize(80,80));
    }
    if(m_posList.at(id)->val==4)
    {
    m_posList.at(id)->Leibtn2->setIcon(QPixmap("://image/4.png"));
    m_posList.at(id)->Leibtn2->setIconSize(QSize(80,80));
    }
    if(m_posList.at(id)->val==5)
    {
    m_posList.at(id)->Leibtn2->setIcon(QPixmap("://image/5.png"));
    m_posList.at(id)->Leibtn2->setIconSize(QSize(80,80));
    }
    if(m_posList.at(id)->val==6)
    {
    m_posList.at(id)->Leibtn2->setIcon(QPixmap("://image/6.png"));
    m_posList.at(id)->Leibtn2->setIconSize(QSize(80,80));
    }
    if(m_posList.at(id)->val==7)
    {
    m_posList.at(id)->Leibtn2->setIcon(QPixmap("://image/7.png"));
    m_posList.at(id)->Leibtn2->setIconSize(QSize(80,80));
    }
    if(m_posList.at(id)->val==8)
    {
    m_posList.at(id)->Leibtn2->setIcon(QPixmap("://image/8.png"));
    m_posList.at(id)->Leibtn2->setIconSize(QSize(80,80));
    }
    }
    win_end();
}
void MainWindow::win_end()
{
 for(int j=0;j<m_posList.size();j++)
 {
     if(m_posList.at(j)->val>=0 )
     {
         if(m_posList.at(j)->clickFlag==1||m_posList.at(j)->clickFlag==2)
         k1=1;
         else
        return;
     }
 }
     win().exec();
}
void MainWindow::dispaly_ray(int id)//点击到雷后显示出全部的雷
{
    //disconnect(m_bg,SIGNAL(buttonClicked(int)),this,SLOT(isCorrect(int)));  //点击按钮　调用槽函数
    for(int j=0;j<m_posList.size();j++)
  {
        if( m_posList.at(j)->clickFlag == 3 && m_posList.at(j)->val !=-1)
       {
            m_posList.at(j)->Leibtn2->setEnabled(false);
            if(m1==8 && n1==8)
           {
            m_posList.at(j)->Leibtn2->setIcon(QPixmap("://image/error.png"));
            m_posList.at(j)->Leibtn2->setIconSize(QSize(80,80));
            }
            else
            {
                m_posList.at(j)->Leibtn2->setIcon(QPixmap("://image/error.png"));
                m_posList.at(j)->Leibtn2->setIconSize(QSize(40,40));
            }
        }
 }
    for(int k;k<numbersList.size();k++)
{
    if(numbersList[k] != id &&m_posList.at(numbersList[k])->clickFlag != 3 )
    {
    m_posList.at(numbersList[k])->Leibtn2->setEnabled(false);
    m_posList.at(numbersList[k])->Leibtn2->setIcon(QPixmap("://image/bomb.png"));
    m_posList.at(numbersList[k])->Leibtn2->setIconSize(QSize(80,80));
    }
 }
    for(int r=0;r<m_posList.size();r++)
        m_posList.at(r)->Leibtn2->setEnabled(false);
}
void MainWindow::mousePressEvent( QMouseEvent * event)//鼠标点击事件，插红旗
{
    int px=event->x();
    int py=event->y();
        if(event->button()==Qt::RightButton && m1==8 && n1==8)//8*8 插小红旗
           {
              int   m=(px-100)/80;
                int n=(py-80)/80 ;
           if(m_posList.at(n*8+m-1)->clickFlag==3)
               {
               m_posList.at(n*8+m-1)->Leibtn2->setIcon(QPixmap(""));
               m_posList.at(n*8+m-1)->clickFlag=0;
               }
         else
          {
           m_posList.at(n*8+m-1)->clickFlag=3;
            m_posList.at(n*8+m-1)->Leibtn2->setIcon(QPixmap("://image/Flag.png"));
            m_posList.at(n*8+m-1)->Leibtn2->setIconSize(QSize(80,80));
           }
            }
        else
        if(event->button()==Qt::RightButton && m1==30 && n1==16)//30*16插小红旗
        {
            int m=(px-30)/40;
            int n=(py-70)/40;
       if(m_posList.at(n*30+m-1)->clickFlag==3)
           {
           m_posList.at(n*30+m-1)->Leibtn2->setIcon(QPixmap(""));
           m_posList.at(n*30+m-1)->clickFlag=0;
           }
     else
      {
        m_posList.at(n*30+m-1)->clickFlag=3;
        m_posList.at(n*30+m-1)->Leibtn2->setIcon(QPixmap("://image/Flag.png"));
        m_posList.at(n*30+m-1)->Leibtn2->setIconSize(QSize(40,40));
       }
       }
        else
        if(event->button()==Qt::RightButton )//16*16和自定义插小红旗
            {
                int m=(px-80)/40;
                int n=(py-70)/40;
           if(m_posList.at(n*m1+m-2)->clickFlag==3)
               {
               m_posList.at(n*m1+m-2)->Leibtn2->setIcon(QPixmap(""));
               m_posList.at(n*m1+m-2)->clickFlag=0;
               }
         else
          {
            m_posList.at(n*m1+m-2)->clickFlag=3;
            m_posList.at(n*m1+m-2)->Leibtn2->setIcon(QPixmap("://image/Flag.png"));
            m_posList.at(n*m1+m-2)->Leibtn2->setIconSize(QSize(40,40));
           }
           }
}
void MainWindow::xianshi(int id)//显示对应按钮的图片
{
    m_posList.at(id)->Leibtn2->setEnabled(false);
    if(m_posList.at(id)->val==-1)
    {
    m_posList.at(id)->Leibtn2->setIcon(QPixmap("://image/bomb.png"));
    m_posList.at(id)->Leibtn2->setIconSize(QSize(80,80));
  }
    if(m_posList.at(id)->val==1)
    {
    m_posList.at(id)->Leibtn2->setIcon(QPixmap("://image/1.png"));
    m_posList.at(id)->Leibtn2->setIconSize(QSize(80,80));
}
    if(m_posList.at(id)->val==2)
    {
    m_posList.at(id)->Leibtn2->setIcon(QPixmap("://image/2.png"));
    m_posList.at(id)->Leibtn2->setIconSize(QSize(80,80));
}
    if(m_posList.at(id)->val==3)
    {
    m_posList.at(id)->Leibtn2->setIcon(QPixmap("://image/3.png"));
    m_posList.at(id)->Leibtn2->setIconSize(QSize(80,80));
}
    if(m_posList.at(id)->val==4)
    {
    m_posList.at(id)->Leibtn2->setIcon(QPixmap("://image/4.png"));
    m_posList.at(id)->Leibtn2->setIconSize(QSize(80,80));
}
    if(m_posList.at(id)->val==5)
    {
    m_posList.at(id)->Leibtn2->setIcon(QPixmap("://image/5.png"));
    m_posList.at(id)->Leibtn2->setIconSize(QSize(80,80));
}
    if(m_posList.at(id)->val==6)
    {
    m_posList.at(id)->Leibtn2->setIcon(QPixmap("://image/6.png"));
    m_posList.at(id)->Leibtn2->setIconSize(QSize(80,80));
}
    if(m_posList.at(id)->val==7)
    {
    m_posList.at(id)->Leibtn2->setIcon(QPixmap("://image/7.png"));
    m_posList.at(id)->Leibtn2->setIconSize(QSize(80,80));
}
    if(m_posList.at(id)->val==8)
    {
    m_posList.at(id)->Leibtn2->setIcon(QPixmap("://image/8.png"));
    m_posList.at(id)->Leibtn2->setIconSize(QSize(80,80));
}
}
void MainWindow::spread(int i)
{
    int col = i/m1;
    int row=i%m1;
    int m=m1;
    int n=n1;

    if(col != 0 && m_posList.at(i-m)->val !=-1 &&m_posList.at(i-m)->clickFlag == 0)
    {
        m_posList.at(i-m)->clickFlag=2;
        m_posList.at(i-m)->Leibtn2->setEnabled(false);
        xianshi(i-m);
         if(m_posList.at(i-m)->val ==0)
         {
             spread(i-m);
         }
    }
    if(row != 0 &&m_posList.at(i-1)->val != -1 && m_posList.at(i-1)->clickFlag ==0)
    {
        m_posList.at(i-1)->clickFlag=2;
        m_posList.at(i-1)->Leibtn2->setEnabled(false);
        xianshi(i-1);
        if(m_posList.at(i-1)->val == 0)
        {
            spread(i-1);
        }
    }
    if(row<m-1 && m_posList.at(i+1)->val != -1 && m_posList.at(i+1)->clickFlag ==0)
    {
        m_posList.at(i+1)->clickFlag=2;
        m_posList.at(i+1)->Leibtn2->setEnabled(false);
        xianshi(i+1);
        if(m_posList.at(i+1)->val == 0)
        {
            spread(i+1);
        }
    }
    if(col <n-1 && m_posList.at(i+m)->val != -1 && m_posList.at(i+m)->clickFlag == 0)
    {
        m_posList.at(i+m)->clickFlag=2;
        m_posList.at(i+m)->Leibtn2->setEnabled(false);
        xianshi(i+m);
        if(m_posList.at(i+m)->val == 0)
        {
            spread(i+m);
        }
    }
}
void MainWindow::on_pushButton_4_clicked()
{
    ui->pushButton->setEnabled(true);
    ui->pushButton_10->setEnabled(true);
    yincang();
     anjian3(16,16,40);
      m1 =16;
      n1 =16;
}

void MainWindow::on_pushButton_5_clicked()
{
    ui->pushButton->setEnabled(true);
    ui->pushButton_10->setEnabled(true);
    yincang();
     anjian1(30,16,99);
      m1 =30;
      n1 =16;
}

void MainWindow::on_pushButton_clicked()
{
    pTimer->stop();
    yincang();
    for(int i=0;i<m_posList.size();i++)
        {
        m_posList.at(i)->Leibtn2->setVisible(false);
    }
    ui->textEdit->setVisible(true);
    ui->pushButton->setVisible(false);
    ui->pushButton_10->setVisible(true);
}
void MainWindow::on_pushButton_10_clicked()
{
    pTimer->start(1000);
    for(int i=0;i<m_posList.size();i++)
        {
        m_posList.at(i)->Leibtn2->setVisible(true);
    }
    ui->textEdit->setVisible(false);
    ui->pushButton->setVisible(true);
    ui->pushButton_10->setVisible(false);
}
void MainWindow::on_toolButton_clicked()
{
    //on_pushButton_3_clicked();
    ui->pushButton->setEnabled(false);
    ui->pushButton_10->setEnabled(false);
    ui->toolButton->setVisible(false);
    ui->toolButton_3->setVisible(true);
    ui->widget_3->setVisible(true);
    ui->widget_2->setVisible(false);
    for(int i=0;i<m_posList.size();i++)
    {
    m_posList.at(i)->Leibtn2->close();
    }
    m_posList.clear();
}
void MainWindow::on_toolButton_3_clicked()
{
    pTimer->stop();
  // time= QTime(0,0,0,0);
   // showTime();
    for(int i=0;i<m_posList.size();i++)
    {
    m_posList.at(i)->Leibtn2->close();
    }
    m_posList.clear();
    ui->pushButton->setEnabled(false);
    ui->pushButton_10->setEnabled(false);
    ui->toolButton->setVisible(true);pTimer->stop();
    ui->toolButton_3->setVisible(false);
    ui->widget_3->setVisible(true);
    ui->widget_2->setVisible(false);
}
void MainWindow::on_pushButton_9_clicked()//自定义开始游戏槽函数
{
    ui->pushButton->setEnabled(true);
    ui->pushButton_10->setEnabled(true);
     m1=ui->spinBox->text().toInt();
     n1=ui->spinBox_2->text().toInt();
    c=ui->spinBox_3->text().toInt();
    anjian3(m1,n1,c);
    ui->widget_2->setVisible(false);
    ui->textEdit->setVisible(false);
}
void MainWindow::on_action_7_triggered()
{
    g.exec();
}
void MainWindow::on_action_5_triggered()
{
    shouxuanxiang().exec();
}

void MainWindow::on_action_6_triggered()
{
    help().exec();
}

void MainWindow::on_action_8_triggered()
{
    close();
}

void MainWindow::on_action_3_triggered()
{
    showFullScreen();
    ui->pushButton_2->setVisible(false);
    ui->pushButton_7->setVisible(true);
}
void MainWindow::on_action_triggered()
{
    ui->toolButton->setVisible(false);
    ui->toolButton_3->setVisible(true);
    ui->widget_3->setVisible(true);
    for(int i=0;i<m_posList.size();i++)
    {
    m_posList.at(i)->Leibtn2->close();
    }
    m_posList.clear();
}
void MainWindow::on_toolButton_2_clicked()//提示槽函数
{
    int i=0;
    for(i;i<m_posList.size() ;i++)
        {
        if(m_posList.at(i)->val>=0 && m_posList.at(i)->clickFlag==0)
            {
    isCorrect(i);
    break;
    }
  }
    win_end();
}
