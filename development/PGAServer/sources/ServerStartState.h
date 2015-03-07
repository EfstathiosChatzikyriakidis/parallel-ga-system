#ifndef _SERVER_START_STATE_H_
#define _SERVER_START_STATE_H_

class IServerState;
class ServerManager;

class ServerStartState : public IServerState
{
    public:
        ServerStartState ();
        ~ServerStartState ();

        bool stop (ServerManager & sm);
        bool start (ServerManager & sm);
};

#endif /* _SERVER_START_STATE_H_ */
