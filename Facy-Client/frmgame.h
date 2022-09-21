#ifndef FRMGAME_H
#define FRMGAME_H

#include <QMainWindow>

namespace Ui {
class FrmGame;
}

class FrmGame : public QMainWindow
{
    Q_OBJECT

public:
    explicit FrmGame(QWidget *parent = nullptr);
    ~FrmGame();

private:
    Ui::FrmGame *ui;
};

#endif // FRMGAME_H
