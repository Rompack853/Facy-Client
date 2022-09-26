#include "frmoptions.h"
#include "ui_frmoptions.h"

FrmOptions::FrmOptions(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FrmOptions)
{
    ui->setupUi(this);
    changeOptionPage(0);
}

FrmOptions::~FrmOptions()
{
    delete ui;
}

void FrmOptions::changeOptionPage(int page)
{
    ui->mainWindow->setCurrentIndex(page);
}

/*==================================================
 *
 *      Sidebar
 *
 ==================================================*/
void FrmOptions::on_btnGeneral_clicked()
{
    changeOptionPage(0);
}


void FrmOptions::on_btnNetwork_clicked()
{
    changeOptionPage(1);
}
/*==================================================
 *
 *      Inhaltsbereich
 *
 ==================================================*/



