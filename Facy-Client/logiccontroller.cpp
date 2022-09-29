#include "logiccontroller.h"

/*
 * Attention: Not all of the Code in this Class was written by the Team:
 * Encryption with QSslSocket has been inspired by:
 * https://github.com/jbagg/QSslSocket-example
 * */

/**
 * Constructor
 * @brief LogicController::LogicController
 */
LogicController::LogicController() : QObject()
{
    client = new QSslSocket();
    connect(client, SIGNAL(readyRead()), this, SLOT(recieve()));
    connect(client, SIGNAL(disconnected()), this, SLOT(disconnect()));
    connect(client, SIGNAL(sslErrors(QList<QSslError>)), this, SLOT(sslErrors(QList<QSslError>)));

    client->setPrivateKey("../Encryption/blue_local.key");
    client->setLocalCertificate("../Encryption/blue_local.pem");
    client->setPeerVerifyMode(QSslSocket::VerifyNone);

    //connect(client, SIGNAL(readyRead()), this ,SLOT(recieve()));
}//Constuctor()

/**
 * Sends data to the Server
 * @brief LogicController::send
 * @param message
 */
void LogicController::send(QString message){
    if(client->waitForEncrypted(5000)){
        qDebug() << "[" + id + "] sending: " + message;
        client->write(message.toLatin1());
    } else {
        //verbindung fehlgeschlagen
        qDebug() << "unable to connect to server.";
        exit(0);
    }

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
    //client->connectToHost(serverIP, port);
    client->connectToHostEncrypted(serverIP, port);
}//connect()

/**
 * Disconnects from the Server
 * @brief LogicController::disconnect
 */
void LogicController::disconnect(){
    client->close();
}

/**
 * Checks if inserted email is valid
 *
 * @brief LogicController::checkEmail
 * @param QString email
 * @return QString out
 */
QString LogicController::checkEmail(QString email)
{
    QString out = error[EMAIL];

    //Check1: Email enthält ein(!) "@"
    if(email.count("@") == 1)
    {
        QList temp =email.split("@");

        //Check:2 Email enthält ein(!) "."
        if(temp[1].count(".") == 1)
        {
            temp = temp[1].split(".");

            //Check:3 Email enthält min. ein character vor und nach "."
            if(temp[0] != "" && temp[1] != "")
            {
                out = "";
            }
        }
    }
   return out;
}

/**
 * Checks the safety level of the inserted password
 * @brief LogicController::checkPassword
 * @param QString password
 * @return QList<QString> out
 *
 *      index 0 = Error:UppercaseMissing,
 *      index 1 = Error:LowercaseMissing,
 *      index 2 = Error:NumberMissing,
 *      index 3 = Error:SymbolMissing,
 *      index 4 = Error:LengthUnder12,
 */
QList<QString> LogicController::checkPassword(QString password)
{
    QList<QString> out =
    {
        error[PW_UPPERCASE],
        error[PW_LOWERCASE],
        error[PW_NUMBER],
        error[PW_SYMBOL],
        error[PW_LENGTH]
    };

    QString specialCharacters = " !#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
    specialCharacters += '"';

    for (QChar temp: password)
    {
        //Check1: if character is uppercase
        if(temp.isUpper())
        {
            out[0] = "";
        }
        //Check2: if character is lowercase
        if(temp.isLower())
        {
            out[1] = "";
        }
        //Check3: if character is number
        if(temp.isNumber())
        {
            out[2] = "";
        }
        //Check4: if character is symbol
        if(specialCharacters.contains(temp))
        {
            out[3] = "";
        }
    }
    //Check5: if passwort is at least 12 characters long
    if(password.length() >= 12)
    {
        out[4] = "";
    }
    return out;
}//disconnect()

/**
 * Prints SslErrors to the Console
 * @brief LogicController::sslErrors
 * @param errors
 */
void LogicController::sslErrors(QList<QSslError> errors){

    for(QSslError error: errors){
        qDebug() << error.errorString();
    }//for
}

/**
 * @brief LogicController::convertImageToByte
 * @param img
 * @return
 */
QByteArray LogicController::convertImageToByte(QImage* img)
{
    //ByteArray Output
    QByteArray out;

    //Filling ByteArray with data from image
    out = out.fromRawData((const char*) img->bits(), img->sizeInBytes());

    return out;
}

// WIP NOT WORKING AT THE MOMENT
// Problem: Can't create an Image with data from byteArray, out = null
/**
 * @brief LogicController::convertByteToImage
 * @param byteArray
 * @return
 */
QImage* LogicController::convertByteToImage(QByteArray byteArray)
{
    //Image Output
    QImage* out = new QImage(10, 10, QImage::Format_RGB888);
    out = new QImage(out->fromData(reinterpret_cast<const uchar *>(byteArray.data()),byteArray.size()));

    //out = QImage::fromData(byteArray);
    //bool ok = false;
    //bool ok = out->loadFromData((const char*)byteArray.data(), byteArray.length());
    //out->loadFromData(reinterpret_cast<const uchar *>(byteArray.data()),byteArray.length());
    //qDebug() <<"FUCKING IMAGE " << ok;
    return out;
}
