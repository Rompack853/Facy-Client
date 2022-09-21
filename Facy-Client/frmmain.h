#ifndef FRMMAIN_H
#define FRMMAIN_H

#include <QMainWindow>

namespace Ui {
class FrmMain;
}

class FrmMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit FrmMain(QWidget *parent = nullptr);
    ~FrmMain();

private:
    Ui::FrmMain *ui;
};

#endif // FRMMAIN_H
