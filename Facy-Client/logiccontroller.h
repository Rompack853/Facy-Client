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
#include <QMetaEnum>

class LogicController : public QObject
{
        Q_OBJECT
public:
    static LogicController& getInstance()
    {
        static LogicController* instance = new LogicController();
        return *instance;
    }

    QMap<int, QString> send(QString message);
    void connectTo(QString serverIP, int port);

    QMap<int, QString> checkEmail(QString email);
    QMap<int, QString> checkPassword(QString password);
    QByteArray convertImageToByte(QImage* img);
    QImage* convertByteToImage(QByteArray byteArray);
    QMap<int, QString> accLogin(QString email, QString password);
    QMap<int, QString> accRegister(QString email, QString password);

    QList<QString> error =
    {
        //Email
        "Email ungültig",

        //Password
        "Großbuchstabe fehlt",
        "Kleinbuchstabe fehlt",
        "Zahl fehlt",
        "Zeichen fehlt",
        "Passwort zu kurz",
        "Passwörter stimmen nicht überein",

        //Connection
        "Verbindung fehlgeschlagen",
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
        PW_LENGTH,
        PW_DIFFERENT,

        //Connection
        CN_FAILED
    };

private:
    LogicController();

    LogicController(const LogicController&) = delete;
    LogicController& operator=(const LogicController&) = delete;
    LogicController(LogicController&&) = delete;
    LogicController& operator=(LogicController&&) = delete;

    QMap<int, QString> startGame();
    QMap<int, QString> joinExistingGame();
    QList<bool> checkActiveGames();

    QSslSocket* client;
    //QTcpSocket* client;
    QString id = "1";

private slots:
    void recieve();
    void disconnect();
    void sslErrors(QList<QSslError> sslErrors);

};
#endif // LOGICCONTROLLER_H
