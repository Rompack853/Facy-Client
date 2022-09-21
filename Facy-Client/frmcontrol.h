#ifndef FRMCONTROL_H
#define FRMCONTROL_H

#include <QMainWindow>

namespace Ui {
class FrmControl;
}

class FrmControl : public QMainWindow
{
    Q_OBJECT

public:
    explicit FrmControl(QWidget *parent = nullptr);
    ~FrmControl();

private:
    Ui::FrmControl *ui;
};

#endif // FRMCONTROL_H
