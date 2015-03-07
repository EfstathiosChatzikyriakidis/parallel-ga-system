#include "IServerState.h"
#include "ServerManager.h"
#include "ServerStopState.h"
#include "Server.h"

using namespace std;

ServerManager::ServerManager ()
{
    _server = QSharedPointer<Server> (new Server ());

    _state = QSharedPointer<IServerState> (new ServerStopState ());
}

ServerManager::~ServerManager ()
{
}

void ServerManager::setPort (const QString & port)
{
    if (port.isNull () || port.isEmpty ())
    {
        throw invalid_argument ("The port number cannot be empty or null!");
    }

    bool success;

    unsigned short value = port.toUShort (&success);

    if (success)
    {
        _server->setPort (value);
    }
    else
    {
        throw logic_error ("Cannot parse the port number as an unsigned short integer!");
    }
}

void ServerManager::setHost (const QString & host)
{
    if (host.isNull () || host.isEmpty ())
    {
        throw invalid_argument ("The host address cannot be empty or null!");
    }

    _server->setHost (QHostAddress (host));
}

void ServerManager::setState (const QSharedPointer<IServerState> & state)
{
    _state = state;
}

bool ServerManager::start ()
{
    return _state->start (*this);
}

bool ServerManager::stop ()
{
    return _state->stop (*this);
}
