#include "frmmain.h"
#include "ui_frmmain.h"

FrmMain::FrmMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FrmMain)
{
    ui->setupUi(this);
    changeFacyPage(0);
    changeMainPage(0);

}

FrmMain::~FrmMain()
{
    delete ui;
}

void FrmMain::changeFacyPage(int page)
{
    ui->facyWindow->setCurrentIndex(page);
}

void FrmMain::openWindow(int window)
{
    switch (window) {
    case OPTIONSWINDOW:
        frmOptions.setWindowFlags(Qt::WindowCloseButtonHint);
        frmOptions.show();
        break;

    case ACCOUNTWINDOW:
        frmAccount.setWindowFlags(Qt::WindowCloseButtonHint);
        frmAccount.show();
        break;

    case FILEEXPLORER:
        fileExplorer.setWindowFlags(Qt::WindowCloseButtonHint);
        fileExplorer.show();
        break;

    default:
        break;
    }
}


/*==================================================
 *
 *      Login   -   Inhaltsbereich
 *
 ==================================================*/



void FrmMain::on_loginClbShowPw_stateChanged(int state)
{
    if(state == 0) {
        ui->loginLePassword->setEchoMode(QLineEdit::Password);
    }else {
        ui->loginLePassword->setEchoMode(QLineEdit::Normal);
    }
}


void FrmMain::on_loginBtnLogin_clicked()
{
    changeFacyPage(1);
}

void FrmMain::on_loginBtnOptions_clicked()
{
    openWindow(OPTIONSWINDOW);
}

void FrmMain::on_loginClbSignUp_clicked()
{
    openWindow(ACCOUNTWINDOW);
}


/*==================================================
 *
 *      Main    -   Sidebar
 *
 ==================================================*/
void FrmMain::on_btnLogout_clicked()
{
    changeFacyPage(0);
}

void FrmMain::on_btnStart_clicked()
{
    changeMainPage(0);
}


void FrmMain::on_btnScoreboard_clicked()
{
    changeMainPage(1);
}


void FrmMain::on_btnControl_clicked()
{
    changeMainPage(2);
}


void FrmMain::on_btnHelp_clicked()
{

}

void FrmMain::on_btnOptions_clicked()
{
    openWindow(OPTIONSWINDOW);
}

void FrmMain::on_btnGame_clicked()
{
    changeMainPage(3);
}

void FrmMain::changeMainPage(int page)
{
    ui->mainWindow->setCurrentIndex(page);
}

void FrmMain::resizeEvent(QResizeEvent *event)
{
    //ui->gridCards.setWid this->width();
    windowWidth = this->width();
    windowHeight = this->height();

    //Minimumgroesse Picture = 300x300
    //Standardfenstergroesse = 900x500

    /*
    if(windowWidth > 900 && windowHeight > 300) {
        ui->imgPicture->setMinimumSize(300,300);
        ui->imgPicture->setMaximumSize(300,300);
    }
    */
    /*
    QSize picSize = ui->imgPicture->size();
    qDebug() << picSize;
    picSize.scale(picSize,Qt::KeepAspectRatio);
    ui->imgPicture->setFixedSize(picSize);
    */
}

/*==================================================
 *
 *      Main    -   Inhaltsbereich
 *
 ==================================================*/













void FrmMain::on_btnUploadPictures_clicked()
{
    openWindow(FILEEXPLORER);
}

