#ifndef FRMHELP_H
#define FRMHELP_H

#include <QWidget>

namespace Ui {
class FrmHelp;
}

class FrmHelp : public QWidget
{
    Q_OBJECT

public:
    explicit FrmHelp(QWidget *parent = nullptr);
    ~FrmHelp();

private slots:
    void on_btnGeneral_clicked();

    void on_btnGame_clicked();

    void on_btnGroups_clicked();

    void on_btnPictures_clicked();

    void on_btnAccounts_clicked();

private:
    void changeHelpPage(int page);

    enum mainPage{
        GENERAL = 0,
        GAME = 1,
        GROUPS = 2,
        PICTURES = 3,
        ACCOUNTS = 4
    };

    Ui::FrmHelp *ui;
};

#endif // FRMHELP_H
