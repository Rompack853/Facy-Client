#ifndef LOGICCONTROLLER_H
#define LOGICCONTROLLER_H

//#include <QTcpSocket>
#include <QDataStream>
#include <QImage>
#include <QSslSocket>
#include <QSslKey>
#include <QSslCertificate>
#include <QTextCodec>
#include <QPixmap>
#include <QFile>
#include <QIODevice>
#include <QByteArray>

class LogicController : public QObject
{
        Q_OBJECT
public:
    LogicController();


    void send(QString message);
    void connectTo(QString serverIP, int port);

    QString checkEmail(QString email);
    QList<QString> checkPassword(QString password);
    QByteArray convertImageToByte(QImage* img);
    QImage* convertByteToImage(QByteArray byteArray);

private:
    QSslSocket* client;
    QString id = "1";

    QList<QString> error =
    {
        //Email
        "Email ungültig",

        //Password
        "Großbuchstabe fehlt",
        "Kleinbuchstabe fehlt",
        "Zahl fehlt",
        "Zeichen fehlt",
        "Passwort zu kurz"
    };

private slots:
    void recieve();
    void disconnect();
    void sslErrors(QList<QSslError> sslErrors);

};

enum errorE
{
    //Email
    EMAIL,

    //Password
    PW_UPPERCASE,
    PW_LOWERCASE,
    PW_NUMBER,
    PW_SYMBOL,
    PW_LENGTH
};

#endif // LOGICCONTROLLER_H
