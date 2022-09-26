#ifndef FRMACCOUNT_H
#define FRMACCOUNT_H

#include <QWidget>

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
    void on_registerClbShowPw_stateChanged(int state);

private:
    Ui::FrmAccount *ui;
};

#endif // FRMACCOUNT_H
