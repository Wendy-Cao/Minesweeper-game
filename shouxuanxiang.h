#ifndef SHOUXUANXIANG_H
#define SHOUXUANXIANG_H

#include <QDialog>

namespace Ui {
class shouxuanxiang;
}

class shouxuanxiang : public QDialog
{
    Q_OBJECT
    
public:
    explicit shouxuanxiang(QWidget *parent = 0);
    ~shouxuanxiang();
    
private:
    Ui::shouxuanxiang *ui;
};

#endif // SHOUXUANXIANG_H
