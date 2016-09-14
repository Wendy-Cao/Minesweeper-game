#ifndef WIN_H
#define WIN_H

#include <QDialog>

namespace Ui {
class win;
}

class win : public QDialog
{
    Q_OBJECT
    
public:
    explicit win(QWidget *parent = 0);
    ~win();
    
private:
    Ui::win *ui;
};

#endif // WIN_H
