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
    //client = new QTcpSocket();
    connect(client, SIGNAL(readyRead()), this, SLOT(recieve()));
    connect(client, SIGNAL(disconnected()), this, SLOT(disconnect()));
    connect(client, SIGNAL(sslErrors(QList<QSslError>)), this, SLOT(sslErrors(QList<QSslError>)));

    client->setPrivateKey("../Encryption/blue_local.key");
    client->setLocalCertificate("../Encryption/blue_local.pem");
    client->setPeerVerifyMode(QSslSocket::VerifyNone);

    connect(client, SIGNAL(readyRead()), this ,SLOT(recieve()));
}//Constuctor()

/**
 * Sends data to the Server
 * @brief LogicController::send
 * @param message
 */
QMap<int, QString> LogicController::send(QString message)
{
    QMap<int, QString> outErrors;

    if(client->waitForEncrypted(5000)){
        qDebug() << "[" + id + "] sending: " + message;
        client->write(message.toLatin1());
    } else {
        //verbindung fehlgeschlagen
        outErrors.insert(CN_FAILED, error[CN_FAILED]);
        //exit(0);
    }

    return outErrors;
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
QMap<int, QString> LogicController::checkEmail(QString email)
{
    QMap<int, QString> outErrors;

    QRegExp regExEmail("^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\\.[a-zA-Z0-9-.]+$");

    //Check if Email is valid
    if(!regExEmail.exactMatch(email))
    {
        outErrors.insert(EMAIL, error[EMAIL]);
    }

   return outErrors;
}

/**
 * Checks the safety level of the inserted password
 * @brief LogicController::checkPassword
 * @param QString password
 * @return QList<QString> out
 */
QMap<int, QString> LogicController::checkPassword(QString password)
{
    QMap<int, QString> outErrors;

    QRegExp regExLower("[a-z]");
    QRegExp regExUpper("[A-Z]");
    QRegExp regExNumber("[0-9]");
    QRegExp regExSpecial("[ !#$%&'()*+,-./:;<=>?@[\\]^_`{|}~]");

    //Check1: if character is uppercase
    if(!password.contains(regExUpper))
    {
        outErrors.insert(PW_UPPERCASE, error[PW_UPPERCASE]);
    }
    //Check2: if character is lowercase
    if(!password.contains(regExLower))
    {
        outErrors.insert(PW_LOWERCASE, error[PW_LOWERCASE]);
    }
    //Check3: if character is number
    if(!password.contains(regExNumber))
    {
        outErrors.insert(PW_NUMBER, error[PW_NUMBER]);
    }
    //Check4: if character is symbol
    if(!password.contains(regExSpecial))
    {
        outErrors.insert(PW_SYMBOL, error[PW_SYMBOL]);
    }
    //Check5: if passwort is at least 12 characters long
    if(password.length() < 12)
    {
        outErrors.insert(PW_LENGTH, error[PW_LENGTH]);
    }

    return outErrors;
}

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

/**
 * @brief LogicController::accLogin
 * @param email
 * @param password
 * @return
 */
QMap<int, QString> LogicController::accLogin(QString email, QString password)
{
    QMap<int, QString> outErrors;

    //Check if Email is valid
    outErrors = checkEmail(email);

    //Try to login
    if(outErrors.empty()) {
        outErrors = send("LOGIN~"+email+"~"+password);
    }
    return outErrors;
}

/**
 * @brief LogicController::accRegister
 * @param email
 * @param password
 * @return
 */
QMap<int, QString> LogicController::accRegister(QString email, QString password)
{
    QMap<int, QString> outErrors;

    //outTemp = checkEmail(email);
    outErrors.insert(checkEmail(email));

    outErrors.insert(checkPassword(password));

    if(outErrors.empty())
    {
        send("CREATE_USER~"+email+"~"+password);
    }

    return outErrors;
}

//TODO
QMap<int, QString> LogicController::startGame()
{

}

//TODO
QMap<int, QString> LogicController::joinExistingGame()
{

}

//TODO
QList<bool> LogicController::checkActiveGames()
{
    QList<bool> gamesActive;

    return gamesActive;
}
