#include "frmhelp.h"
#include "ui_frmhelp.h"

FrmHelp::FrmHelp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FrmHelp)
{
    ui->setupUi(this);
    changeHelpPage(GENERAL);
}

FrmHelp::~FrmHelp()
{
    delete ui;
}

/*==================================================
 *
 *      Sidebar
 *
 ==================================================*/


void FrmHelp::changeHelpPage(int page)
{
    ui->mainWindow->setCurrentIndex(page);
}

void FrmHelp::on_btnGeneral_clicked()
{
    changeHelpPage(GENERAL);
}

void FrmHelp::on_btnGame_clicked()
{
    changeHelpPage(GAME);
}

void FrmHelp::on_btnGroups_clicked()
{
    changeHelpPage(GROUPS);
}

void FrmHelp::on_btnPictures_clicked()
{
    changeHelpPage(PICTURES);
}

void FrmHelp::on_btnAccounts_clicked()
{
    changeHelpPage(ACCOUNTS);
}

