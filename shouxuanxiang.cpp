#include "shouxuanxiang.h"
#include "ui_shouxuanxiang.h"

shouxuanxiang::shouxuanxiang(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::shouxuanxiang)
{
    ui->setupUi(this);
}

shouxuanxiang::~shouxuanxiang()
{
    delete ui;
}
