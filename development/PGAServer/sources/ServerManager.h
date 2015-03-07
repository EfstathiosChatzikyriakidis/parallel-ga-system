#ifndef _SERVER_MANAGER_H_
#define _SERVER_MANAGER_H_

#include <QSharedPointer>

#include <stdexcept>

class IServerState;

class Server;

class ServerManager
{
    public:
        friend class ServerStopState;
        friend class ServerStartState;

        ServerManager ();
        ~ServerManager ();

        void setPort (const QString & port);
        void setHost (const QString & host);

        bool start ();
        bool stop ();

    private:
        void setState (const QSharedPointer<IServerState> & state);

        QSharedPointer<Server> _server;

        QSharedPointer<IServerState> _state;
};

#endif /* _SERVER_MANAGER_H_ */
