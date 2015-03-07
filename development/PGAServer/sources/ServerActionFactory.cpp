#include "ServerActionFactory.h"

#include "IServerAction.h"
#include "IServerRequest.h"

using namespace std;

ServerActionFactory::ServerActionFactory ()
{
}

ServerActionFactory::~ServerActionFactory ()
{
}

QMap<QString, QSharedPointer<IServerAction> > ServerActionFactory::_actions;

QSharedPointer<IServerAction> ServerActionFactory::getInstance (const QSharedPointer<IServerRequest> & request)
{
    QString reqName = typeid (*request).name ();

    if (_actions.find (reqName) == _actions.end ())
    {
        return QSharedPointer<IServerAction> (NULL);
    }

    return _actions[reqName];
}

bool ServerActionFactory::registerAction (const QSharedPointer<IServerRequest> & request, const QSharedPointer<IServerAction> & action)
{
    QString reqName = typeid (*request).name ();

    if (_actions.contains(reqName))
    {
        return false;
    }

    _actions.insert (reqName, action);

    return true;
}
