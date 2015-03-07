#ifndef _SERVER_ACTION_FACTORY_H_
#define _SERVER_ACTION_FACTORY_H_

#include <QSharedPointer>
#include <QMap>

#include <typeinfo>

class IServerAction;
class IServerRequest;

class ServerActionFactory
{
    private:
        ServerActionFactory ();
        ~ServerActionFactory ();

        static QMap< QString, QSharedPointer<IServerAction> > _actions;

    public:
        static QSharedPointer<IServerAction> getInstance (const QSharedPointer<IServerRequest> & request);

        static bool registerAction (const QSharedPointer<IServerRequest> & request, const QSharedPointer<IServerAction> & action);
};

#endif /* _SERVER_ACTION_FACTORY_H_ */
