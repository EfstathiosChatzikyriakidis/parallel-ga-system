#include "ServerRequestFactory.h"
#include "ServerActionFactory.h"
#include "ServerBestRequest.h"
#include "ServerBestAction.h"
#include "Configuration.h"
#include "ServerLogger.h"
#include "Server.h"

using namespace std;

Server::Server () : QTcpServer ()
{
    ServerRequestFactory::registerRequest (
        QString ("^@best <dimensions='(.*)', values='(.*)'>$"),
        QSharedPointer<IServerRequest> (new ServerBestRequest ())
    );

    ServerActionFactory::registerAction (
        QSharedPointer<IServerRequest> (new ServerBestRequest ()),
        QSharedPointer<IServerAction> (new ServerBestAction ())
    );
}

Server::~Server ()
{
    closeConnections ();
}

void Server::closeConnections ()
{
    foreach (QTcpSocket * client, _clients)
    {
        client->disconnectFromHost();
    }
}

unsigned short Server::getPort ()
{
    return _port;
}

QHostAddress Server::getHost ()
{
    return _host;
}

void Server::setPort (const unsigned short & port)
{
    _port = port;
}

void Server::setHost (const QHostAddress & host)
{
    _host = host;
}

void Server::broadcast (const QTcpSocket & sender, const QString & message)
{
    foreach (QTcpSocket * client, _clients)
    {
        if (client->socketDescriptor() != sender.socketDescriptor())
        {
            client->write ((message + Configuration::lineSeparator).toUtf8 ());
        }
    }
}

void Server::incomingConnection (const int socketDescriptor)
{
    QTcpSocket * client = new QTcpSocket (this);

    client->setSocketDescriptor (socketDescriptor);

    _clients.insert (client);

    LOG_INFO () << "Client connection:" << client->peerAddress ().toString ();

    connect (client, SIGNAL (readyRead ()), this, SLOT (readyRead ()));
    connect (client, SIGNAL (disconnected ()), this, SLOT (disconnected ()));
    connect (client, SIGNAL (disconnected ()), client, SLOT (deleteLater ()));
}

void Server::readyRead ()
{
    QTcpSocket * client = dynamic_cast<QTcpSocket *> (sender ());

    if (client->canReadLine ())
    {
        QString message = QString::fromUtf8 (client->readLine ()).trimmed ();

        QSharedPointer<IServerRequest> request = ServerRequestFactory::getInstance (message);
        if (!request.isNull ())
        {
            QSharedPointer<IServerAction> action = ServerActionFactory::getInstance (request);
            if (!action.isNull ())
            {
                action->execute (*this, *client, message);
            }
        }
    }
}

void Server::disconnected ()
{
    QTcpSocket * client = dynamic_cast<QTcpSocket *> (sender ());

    _clients.remove (client);

    LOG_INFO () << "Client disconnection:" << client->peerAddress ().toString ();
}
