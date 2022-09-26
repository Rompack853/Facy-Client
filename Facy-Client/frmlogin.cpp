#include "frmlogin.h"
#include "ui_frmlogin.h"

FrmLogin::FrmLogin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FrmLogin)
{
    ui->setupUi(this);
    //loadImages();
}

FrmLogin::~FrmLogin()
{
    delete ui;
}

/*
 * Ungenutzte Methode, behalten für eventuell späteres Image rezisen
 */
void FrmLogin::loadImages()
{
    //"../../Facy-Client/images/logo.png"
    //"C:/Users/mondw/Documents/GitHub/Facy-Client/Facy-Client/images/logo.png"
    QPixmap imgLogo("src/images/images/logo.png");
    QLabel* logo = ui->imgLogo;

    qDebug() << logo->minimumSizeHint();
    qDebug() << logo->minimumHeight();


    int w = logo->minimumWidth();
    int h = logo->minimumHeight();
    logo->setPixmap(imgLogo.scaled(w,h,Qt::KeepAspectRatio));
}

void FrmLogin::on_btnLogin_clicked()
{
    frmMain.show();
    this->close();
}


void FrmLogin::on_cbShowPw_stateChanged(int state)
{
    if(state == 0) {
        ui->lePassword->setEchoMode(QLineEdit::Password);
    }else {
        ui->lePassword->setEchoMode(QLineEdit::Normal);
    }
}

