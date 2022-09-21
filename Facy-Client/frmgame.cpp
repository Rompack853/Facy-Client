#include "frmgame.h"
#include "ui_frmgame.h"

FrmGame::FrmGame(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FrmGame)
{
    ui->setupUi(this);
}

FrmGame::~FrmGame()
{
    delete ui;
}
