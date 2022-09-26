#ifndef LOGICCONTROLLER_H
#define LOGICCONTROLLER_H

#include <QTcpSocket>

class LogicController : public QObject
{
        Q_OBJECT
public:
    LogicController();


    void send(QString message);
    void connectTo(QString serverIP, int port);
    void disconnect();
private:
    QTcpSocket* client;
    QString id = "1";
private slots:
    void recieve();

};

enum backend
{
    USERDATA
};

#endif // LOGICCONTROLLER_H
