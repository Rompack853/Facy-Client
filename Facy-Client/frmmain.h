#ifndef FRMMAIN_H
#define FRMMAIN_H

#include <QMainWindow>
#include <QDebug>
#include "frmoptions.h"

namespace Ui {
class FrmMain;
}

class FrmMain : public QMainWindow
{
    Q_OBJECT

public:
    explicit FrmMain(QWidget *parent = nullptr);
    ~FrmMain();

private slots:

    void changeFacyPage(int page);

    void openOptions();

    //Login
    void on_loginClbShowPw_stateChanged(int page);

    void on_loginBtnLogin_clicked();


    //Main
    void on_btnLogout_clicked();

    void on_btnStart_clicked();

    void on_btnScoreboard_clicked();

    void on_btnControl_clicked();

    void on_btnHelp_clicked();

    void changeMainPage(int page);

    void resizeEvent(QResizeEvent* event);

    void on_btnGame_clicked();

    void on_loginBtnOptions_clicked();

    void on_btnOptions_clicked();

private:
    Ui::FrmMain *ui;

    FrmOptions frmOptions;

    int windowWidth = 900;
    int windowHeight = 500;
};

#endif // FRMMAIN_H
