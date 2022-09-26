#ifndef FRMMAIN_H
#define FRMMAIN_H

#include <QMainWindow>
#include <QDebug>

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

private:
    Ui::FrmMain *ui;

    int windowWidth = 900;
    int windowHeight = 500;
};

#endif // FRMMAIN_H
