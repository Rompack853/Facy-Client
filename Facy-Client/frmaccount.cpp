#include "frmaccount.h"
#include "ui_frmaccount.h"

FrmAccount::FrmAccount(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FrmAccount)
{
    ui->setupUi(this);
    ui->accountWindow->setCurrentIndex(0);
}

FrmAccount::~FrmAccount()
{
    delete ui;
}

/*==================================================
 *
 *      Register
 *
 ==================================================*/

void FrmAccount::on_registerCbShowPw_stateChanged(int state)
{
    if(state == 0) {
        ui->registerLePassword1->setEchoMode(QLineEdit::Password);
        ui->registerLePassword2->setEchoMode(QLineEdit::Password);
    }else {
        ui->registerLePassword1->setEchoMode(QLineEdit::Normal);
        ui->registerLePassword2->setEchoMode(QLineEdit::Normal);
    }
}


void FrmAccount::on_registerBtnLogin_clicked()
{
    QString email = ui->registerLeEmail->text();
    QString password1 = ui->registerLePassword1->text();
    QString password2 = ui->registerLePassword2->text();

    QMap<int, QString> outError;
    if(password1 == password2)
    {
        outError = LogicController::getInstance().accRegister(email, password1);
    }
    else
    {
        int errorId = LogicController::errorE::PW_DIFFERENT;
        outError.insert(errorId, LogicController::getInstance().error[errorId]);
    }
    qDebug() << outError;
}

/*==================================================
 *
 *      Reset
 *
 ==================================================*/




void FrmAccount::on_resetCbShowPw_stateChanged(int state)
{
    if(state == 0) {
        ui->resetLePasswordOld->setEchoMode(QLineEdit::Password);
        ui->resetLePasswordNew->setEchoMode(QLineEdit::Password);
    }else {
        ui->resetLePasswordOld->setEchoMode(QLineEdit::Normal);
        ui->resetLePasswordNew->setEchoMode(QLineEdit::Normal);
    }
}

