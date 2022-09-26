#include "frmmain.h"
#include "ui_frmmain.h"

FrmMain::FrmMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FrmMain)
{
    ui->setupUi(this);
    changeMainPage(0);
}

FrmMain::~FrmMain()
{
    delete ui;
}


/*==================================================
 *
 *      Sidebar
 *
 ==================================================*/
void FrmMain::on_btnLogout_clicked()
{

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
 *      Inhaltsbereich
 *
 ==================================================*/





