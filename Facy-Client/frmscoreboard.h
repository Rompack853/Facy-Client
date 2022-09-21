#ifndef FRMSCOREBOARD_H
#define FRMSCOREBOARD_H

#include <QMainWindow>

namespace Ui {
class FrmScoreboard;
}

class FrmScoreboard : public QMainWindow
{
    Q_OBJECT

public:
    explicit FrmScoreboard(QWidget *parent = nullptr);
    ~FrmScoreboard();

private:
    Ui::FrmScoreboard *ui;
};

#endif // FRMSCOREBOARD_H
