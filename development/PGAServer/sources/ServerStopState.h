#ifndef _SERVER_STOP_STATE_H_
#define _SERVER_STOP_STATE_H_

class IServerState;
class ServerManager;

class ServerStopState : public IServerState
{
    public:
        ServerStopState ();
        ~ServerStopState ();

        bool stop (ServerManager & sm);
        bool start (ServerManager & sm);
};

#endif /* _SERVER_STOP_STATE_H_ */
