#include <QApplication>

#include "frmmain.h"
#include <QMutex>
#include <QDebug>
#include <iostream>

void redirectedOutput(QtMsgType, const QMessageLogContext &, const QString &);
QMutex debugOutMutex;

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);

    qInstallMessageHandler(redirectedOutput);

    FrmMain w;
    w.show();
    return a.exec();
}
/**
 * Method from "anycodings.com/1questions/1214573/cannot-debugging-output-in-qt-creator"
 * @brief redirectedOutput
 * @param type
 * @param context
 * @param msg
 */
void redirectedOutput(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    debugOutMutex.lock();
    std::cout << QDateTime::currentDateTime().toString("hh.mm.ss.zzz  ").toStdString() << msg.toStdString() << std::endl;
    if (type == QtFatalMsg) {
        abort();
    }
    debugOutMutex.unlock();
}
