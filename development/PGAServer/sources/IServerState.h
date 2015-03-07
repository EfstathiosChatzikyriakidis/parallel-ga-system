#ifndef _ISERVER_STATE_H_
#define _ISERVER_STATE_H_

class ServerManager;

class IServerState
{
    public:
        virtual ~IServerState ();

        virtual bool stop (ServerManager & sm) = 0;
        virtual bool start (ServerManager & sm) = 0;

    protected:
        IServerState ();
};

#endif /* _ISERVER_STATE_H_ */
