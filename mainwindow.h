#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPushButton>
#include<QPixmap>
#include<boom.h>
#include "about.h"
#include<QTimer>
#include<QTime>
#include "shouxuanxiang.h"
#include"help.h"
#include "win.h"
#include<QMouseEvent>
#include<QPoint>
struct tab
{
 QPushButton *Leibtn2;
int val;//标记雷 数字 和空白
int clickFlag;//按钮是否被点击0：未点击，1用户点击，2扩散点击
};
namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    void yincang();
void anjian1(int index1, int index2,int index3);
void anjian2(int index1,int index2,int index3);
void anjian3(int index1,int index2,int index3);
static QButtonGroup * m_bg;
void xianshi(int id);
void spread(int i);
void dispaly_ray(int id);
void win_end();
virtual  void mousePressEvent(QMouseEvent * event);
    ~MainWindow();
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_clicked();

    void on_pushButton_10_clicked();

    void on_toolButton_clicked();

    void on_toolButton_3_clicked();

    void on_pushButton_9_clicked();
    void on_action_7_triggered();

    void on_action_5_triggered();

    void on_action_6_triggered();

    void on_action_8_triggered();

    void on_action_3_triggered();

    void on_action_triggered();

    void on_toolButton_2_clicked();

public slots:
void isCorrect(int id);
void showTime();
private:
    Ui::MainWindow *ui;
   about   g;
    QTimer *pTimer;
      QTime time;
       QString szTime;
};
#endif // MAINWINDOW_H
