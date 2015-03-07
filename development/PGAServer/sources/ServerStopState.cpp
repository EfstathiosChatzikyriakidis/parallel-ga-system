#include "IServerState.h"
#include "ServerStartState.h"
#include "ServerStopState.h"
#include "ServerManager.h"
#include "ServerLogger.h"
#include "Server.h"

using namespace std;

ServerStopState::ServerStopState ()
{
}

ServerStopState::~ServerStopState ()
{
}

bool ServerStopState::stop (ServerManager & sm)
{
    LOG_WARNING () << "Server is not currently running.";

    return false;
}

bool ServerStopState::start (ServerManager & sm)
{
    if (sm._server->listen (sm._server->getHost (), sm._server->getPort ()))
    {
        QSharedPointer<IServerState> state = QSharedPointer<IServerState> (new ServerStartState ());

        sm.setState(state);

        LOG_INFO () << "Server has started successfully.";

        return true;
    }

    LOG_ERROR () << "Server has failed to start.";

    return false;
}
