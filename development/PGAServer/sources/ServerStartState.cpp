#include "IServerState.h"
#include "ServerStartState.h"
#include "ServerStopState.h"
#include "ServerManager.h"
#include "ServerLogger.h"
#include "Server.h"

using namespace std;

ServerStartState::ServerStartState ()
{
}

ServerStartState::~ServerStartState ()
{
}

bool ServerStartState::stop (ServerManager & sm)
{
    if (sm._server->hasPendingConnections ())
    {
        LOG_WARNING () << "Server has some pending connections.";

        return false;
    }

    sm._server->closeConnections ();

    sm._server->close ();

    QSharedPointer<IServerState> state = QSharedPointer<IServerState> (new ServerStopState ());

    sm.setState (state);

    LOG_INFO () << "Server has stopped successfully.";

    return true;
}

bool ServerStartState::start (ServerManager & sm)
{   
    LOG_WARNING () << "Server is already running and is listening for client connections.";

    return false;
}
