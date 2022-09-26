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
    qDebug() << "[" + id + "] sending: " + message;
    client->write(message.toLatin1());

}//send()

/**
 * Recieves Data from the Server
 * @brief LogicController::recieve
 * @return
 */
void LogicController::recieve(){
    QString input = client->readAll();
    qDebug() << "[" + id + "] recieved: " + input;

    //TODO when recieveing "CLOSE" -> connection got terminated -> Show to user
    //Here you can start working with all the Data
    if(input.indexOf("setID_") == 0){
        id = input.mid(6,input.length());
    }//if

    if(input == "CLOSED"){
        //TODO inform the user, that the Connection has been
        //lost due to a Server-Shutdown
    }

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
