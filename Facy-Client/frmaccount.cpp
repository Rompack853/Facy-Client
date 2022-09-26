#include "frmaccount.h"
#include "ui_frmaccount.h"

FrmAccount::FrmAccount(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FrmAccount)
{
    ui->setupUi(this);
}

FrmAccount::~FrmAccount()
{
    delete ui;
}

void FrmAccount::on_registerClbShowPw_stateChanged(int state)
{
    if(state == 0) {
        ui->registerLePassword1->setEchoMode(QLineEdit::Password);
        ui->registerLePassword2->setEchoMode(QLineEdit::Password);
    }else {
        ui->registerLePassword1->setEchoMode(QLineEdit::Normal);
        ui->registerLePassword2->setEchoMode(QLineEdit::Normal);
    }
}

