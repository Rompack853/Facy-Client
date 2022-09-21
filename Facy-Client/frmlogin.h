#ifndef FRMLOGIN_H
#define FRMLOGIN_H

#include <QMainWindow>
#include <QPixmap>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class FrmLogin; }
QT_END_NAMESPACE

class FrmLogin : public QMainWindow
{
    Q_OBJECT

public:
    FrmLogin(QWidget *parent = nullptr);
    ~FrmLogin();

private slots:
    void on_btnLogin_clicked();

    void on_cbShowPw_stateChanged(int arg1);

private:
    Ui::FrmLogin *ui;
    void loadImages();
};
#endif // FRMLOGIN_H
