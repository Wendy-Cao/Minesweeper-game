#ifndef BOOM_H
#define BOOM_H

#include <QObject>
#include<QPushButton>
#include "mainwindow.h"
#include<QButtonGroup>
#include<QDebug>
#include<QtGlobal>
class boom : public QObject
{
    Q_OBJECT
public:
    int arr[8][8];
    void save_btn();
    void set_ray_btn(int m,int n,int num);
    explicit boom(QObject *parent = 0);
signals:
};
#endif // BOOM_H
