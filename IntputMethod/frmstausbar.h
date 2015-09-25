#ifndef FRMSTAUSBAR_H
#define FRMSTAUSBAR_H

#include <QWidget>

namespace Ui {
class frmStausbar;
}

class frmStausbar : public QWidget
{
    Q_OBJECT

public:
    explicit frmStausbar(QWidget *parent = 0);
    ~frmStausbar();

protected:
    //void paintEvent(QPaintEvent *);

private:
    Ui::frmStausbar *ui;
};

#endif // FRMSTAUSBAR_H
