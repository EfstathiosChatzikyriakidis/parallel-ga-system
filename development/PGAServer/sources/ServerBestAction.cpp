#include "ServerBestAction.h"

#include "Server.h"

using namespace std;

ServerBestAction::ServerBestAction ()
{
}

ServerBestAction::~ServerBestAction ()
{
}

bool ServerBestAction::execute (Server & server, const QTcpSocket & sender, const QString & message)
{
    server.broadcast (sender, message);

    return true;
}
