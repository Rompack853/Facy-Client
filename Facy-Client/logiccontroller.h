#ifndef LOGICCONTROLLER_H
#define LOGICCONTROLLER_H

#include <QObject>

class LogicController
{
public:
    LogicController();

private:
    QString sendData(QString key, QString input[]);

    QString requestData(QString key);
};

enum backend
{
    USERDATA
};

#endif // LOGICCONTROLLER_H
