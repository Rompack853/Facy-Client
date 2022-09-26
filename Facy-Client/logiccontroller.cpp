#include "logiccontroller.h"

/**
 * Constructor
 * @brief LogicController::LogicController
 */
LogicController::LogicController() : QObject()
{
    client = new QTcpSocket();
    connect(client, SIGNAL(readyRead()), this ,SLOT(recieve()));
}//Constuctor()

/**
 * Sends data to the Server
 * @brief LogicController::send
 * @param message
 */
void LogicController::send(QString message){
    qDebug() << "[" + QString::number(id) + "] sending: " + message;
    client->write(message.toLatin1());

}//send()

/**
 * Recieves Data from the Server
 * @brief LogicController::recieve
 * @return
 */
void LogicController::recieve(){
    QString input = client->readAll();
    qDebug() << "[" + QString::number(id) + "] recieved: " + input;

    //TODO when recieveing "CLOSE" -> connection got terminated -> Show to user
    //Here you can start working with all the Data

}//recieve()

/**
 * Connects to the Server
 * @brief LogicController::connect
 * @param serverIP
 * @param port
 */
void LogicController::connectTo(QString serverIP, int port){
    qDebug() << "connecting...";
    client->connectToHost(serverIP, port);
}//connect()

/**
 * Disconnects from the Server
 * @brief LogicController::disconnect
 */
void LogicController::disconnect(){
    client->close();
}//disconnect()
