#ifndef _SERVER_BEST_ACTION_H_
#define _SERVER_BEST_ACTION_H_

#include "IServerAction.h"

class ServerBestAction : public IServerAction
{
    public:
        ServerBestAction ();
        ~ServerBestAction ();

        bool execute (Server & server, const QTcpSocket & sender, const QString & message);
};

#endif /* _SERVER_BEST_ACTION_H_ */
