#ifndef _ISERVER_ACTION_H_
#define _ISERVER_ACTION_H_

#include <QTcpSocket>

class Server;

class IServerAction
{
    public:
        virtual ~IServerAction ();

        virtual bool execute (Server & server, const QTcpSocket & sender, const QString & message) = 0;

    protected:
        IServerAction ();
};

#endif /* _ISERVER_ACTION_H_ */
