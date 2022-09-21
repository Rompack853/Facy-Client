#include "frmscoreboard.h"
#include "ui_frmscoreboard.h"

FrmScoreboard::FrmScoreboard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FrmScoreboard)
{
    ui->setupUi(this);
}

FrmScoreboard::~FrmScoreboard()
{
    delete ui;
}
