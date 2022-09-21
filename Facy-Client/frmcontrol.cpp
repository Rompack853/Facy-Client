#include "frmcontrol.h"
#include "ui_frmcontrol.h"

FrmControl::FrmControl(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FrmControl)
{
    ui->setupUi(this);
}

FrmControl::~FrmControl()
{
    delete ui;
}
