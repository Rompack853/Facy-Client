#ifndef FRMMAIN_H
#define FRMMAIN_H

#include <QMainWindow>
#include <QDebug>
#include "frmoptions.h"
#include "frmaccount.h"
#include "fileexplorer.h"
#include "logiccontroller.h"
#include "frmhelp.h"
#include "QFileDialog"
#include <QMessageBox>

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

    void openWindow(int window);

    //Login
    void on_loginBtnLogin_clicked();


    //Main

    void changeMainPage(int page);

    void resizeEvent(QResizeEvent* event);

    void on_btnGame_clicked();

    void on_loginBtnOptions_clicked();

    void on_loginClbSignUp_clicked();

    void on_btnUploadPictures_clicked();


    void on_loginCbShowPw_stateChanged(int state);

    void on_sidebarBtnOptions_clicked();

    void on_sidebarBtnLogout_clicked();

    void on_sidebarBtnScoreboard_clicked();

    void on_sidebarBtnStart_clicked();

    void on_sidebarBtnHelp_clicked();

    void on_sidebarBtnInfo_clicked();

    void on_sidebarBtnControl_clicked();

private:
    Ui::FrmMain *ui;

    FrmOptions frmOptions;
    FrmAccount frmAccount;
    FileExplorer fileExplorer;
    FrmHelp frmHelp;

    int windowWidth = 900;
    int windowHeight = 500;

    enum mainPage{
        START = 0,
        SCOREBOARD = 1,
        CONTROL = 2,
        GAME = 3
    };
    enum window{
        OPTIONSWINDOW,
        ACCOUNTWINDOW,
        FILEEXPLORER,
        HELPWINDOW
    };

};

#endif // FRMMAIN_H
