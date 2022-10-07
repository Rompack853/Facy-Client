#include "frmmain.h"
#include "ui_frmmain.h"

FrmMain::FrmMain(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FrmMain)
{
    ui->setupUi(this);
    changeFacyPage(0);
    changeMainPage(0);

    //================================Eingefuegt von Roman=========
    qDebug() << "Info: Server muss vor dem Client gestartet werden.\n"
                "ansonsten keine Verbingung möglich.";
    //starts with a connect to the Server

    LogicController::getInstance().connectTo("127.0.0.1", 8080);
    LogicController::getInstance().send("Test Nachricht.");
    /*TODO implement all actions in this application when recieving
    codes and Data from the Server*/
    //================================Eingefuegt von Roman=========
}

FrmMain::~FrmMain()
{
    delete ui;
}

/**
 * @brief FrmMain::changeFacyPage
 * @param page
 */
void FrmMain::changeFacyPage(int page)
{
    ui->facyWindow->setCurrentIndex(page);
}

/**
 * Opens the selected Window in front
 * @brief FrmMain::openWindow
 * @param window
 */
void FrmMain::openWindow(int window)
{
    switch (window) {
    case OPTIONSWINDOW:
        frmOptions.setWindowFlags(Qt::WindowCloseButtonHint);
        frmOptions.show();
        break;

    case ACCOUNTWINDOW:
        frmAccount.setWindowFlags(Qt::WindowCloseButtonHint);
        frmAccount.show();
        break;

    case FILEEXPLORER:
        fileExplorer.setWindowFlags(Qt::WindowCloseButtonHint);
        fileExplorer.show();
        break;

    case HELPWINDOW:
        frmHelp.setWindowFlags(Qt::WindowCloseButtonHint);
        frmHelp.show();
        break;

    default:
        break;
    }
}

/*==================================================
 *
 *      Login   -   Inhaltsbereich
 *
 ==================================================*/


void FrmMain::on_loginBtnLogin_clicked()
{
    QString email = ui->loginLeEmail->text();
    QString password = ui->loginLePassword->text();


    QMap<int, QString> outError = LogicController::getInstance().accLogin(email, password);

    qDebug() << outError;

    changeFacyPage(1);
}

void FrmMain::on_loginBtnOptions_clicked()
{
    openWindow(OPTIONSWINDOW);
}

void FrmMain::on_loginClbSignUp_clicked()
{
    openWindow(ACCOUNTWINDOW);
}

/*==================================================
 *
 *      Main    -   Sidebar
 *
 ==================================================*/

/**
 * @brief FrmMain::changeMainPage
 * @param page
 */
void FrmMain::changeMainPage(int page)
{
    ui->mainWindow->setCurrentIndex(page);
}

void FrmMain::on_sidebarBtnLogout_clicked()
{
    changeFacyPage(0);
}

void FrmMain::on_sidebarBtnStart_clicked()
{
    changeMainPage(START);
}

void FrmMain::on_sidebarBtnScoreboard_clicked()
{
    changeMainPage(SCOREBOARD);
}

void FrmMain::on_sidebarBtnControl_clicked()
{
    changeMainPage(CONTROL);
}

void FrmMain::on_sidebarBtnOptions_clicked()
{
    openWindow(OPTIONSWINDOW);
}

void FrmMain::on_sidebarBtnHelp_clicked()
{
    openWindow(HELPWINDOW);
}

void FrmMain::on_sidebarBtnInfo_clicked()
{
    QMessageBox helpBox;
    helpBox.setWindowTitle("Info");
    helpBox.setText("Schulprojekt Facefinder aka. \"Facy\"");
    QString text =
            "Gruppenmitglieder:\n Roman Kretzschmar & Marius Hannappel \n\n"
            "Arbeitszeitraum:\n 1. Schulblock im 3. Ausbildungsjahr + 1 Woche Verlängerung (07.09.22 - 07.10.22)\n\n"
            "Das Projekt konnte aufgrund einem Wechsel der Technologien 2 Wochen nach Beginn, sowie Problemen bei der Implementierung verschiedener Funktionalitäten nicht im ursprünglichen Zeitraum fertiggestellt werden.\n\n";

    helpBox.setInformativeText(text);
    helpBox.setStandardButtons(QMessageBox::Ok);
    helpBox.exec();
}

void FrmMain::resizeEvent(QResizeEvent *event)
{
    //ui->gridCards.setWid this->width();
    windowWidth = this->width();
    windowHeight = this->height();

    //Minimumgroesse Picture = 300x300
    //Standardfenstergroesse = 900x500

    /*
    if(windowWidth > 900 && windowHeight > 300) {
        ui->imgPicture->setMinimumSize(300,300);
        ui->imgPicture->setMaximumSize(300,300);
    }
    */
    /*
    QSize picSize = ui->imgPicture->size();
    qDebug() << picSize;
    picSize.scale(picSize,Qt::KeepAspectRatio);
    ui->imgPicture->setFixedSize(picSize);
    */
}

/*==================================================
 *
 *      Main    -   Inhaltsbereich
 *
 ==================================================*/

/**
 * @brief FrmMain::on_btnUploadPictures_clicked
 */
void FrmMain::on_btnUploadPictures_clicked()
{
    //open Filebrowser to select an image
    QFileDialog fileDialog(this);
    fileDialog.setFileMode(QFileDialog::ExistingFile);
    QString path = "C:/Users/mondw/Documents/GitHub/Facy-Client/Facy-Client/images";
    QString filter = "Images (*.png *.xpm *.jpg)";
    QString filename = fileDialog.getOpenFileName(this, "Open files",path ,filter);

    //save selected image as QImage
    QImage* tempImg = new QImage(filename);

    if(!tempImg->isNull())
    {

        //Consoleoutput for properties of the selected image
        qDebug() << "SelectedImage:" << *tempImg;

        QByteArray tempBa = LogicController::getInstance().convertImageToByte(tempImg);

        //currently not working: returns QImage(null)
        QImage* tempImg = LogicController::getInstance().convertByteToImage(tempBa);

        //Consoleoutput for properties of the converted image (to bytes and back to image)
        qDebug() << "\nConvertedImgList:" << *tempImg;
    }
}

/**
 * @brief FrmMain::on_loginCbShowPw_stateChanged
 * @param state
 */
void FrmMain::on_loginCbShowPw_stateChanged(int state)
{
    if(state == 0) {
        ui->loginLePassword->setEchoMode(QLineEdit::Password);
    }else {
        ui->loginLePassword->setEchoMode(QLineEdit::Normal);
    }
}

void FrmMain::on_btnGame_clicked()
{
    changeMainPage(GAME);
}
