#ifndef FRMACCOUNT_H
#define FRMACCOUNT_H

#include <QWidget>
#include "logiccontroller.h"

namespace Ui {
class FrmAccount;
}

class FrmAccount : public QWidget
{
    Q_OBJECT

public:
    explicit FrmAccount(QWidget *parent = nullptr);
    ~FrmAccount();

private slots:
    void on_registerCbShowPw_stateChanged(int state);

    void on_registerBtnLogin_clicked();

    void on_resetCbShowPw_stateChanged(int state);

private:
    Ui::FrmAccount *ui;
};

#endif // FRMACCOUNT_H
