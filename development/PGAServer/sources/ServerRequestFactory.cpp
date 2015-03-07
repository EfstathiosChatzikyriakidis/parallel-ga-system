#include "ServerRequestFactory.h"

#include "IServerRequest.h"

using namespace std;

ServerRequestFactory::ServerRequestFactory ()
{
}

ServerRequestFactory::~ServerRequestFactory ()
{
}

QMap< QString, QSharedPointer<IServerRequest> > ServerRequestFactory::_requests;

QSharedPointer<IServerRequest> ServerRequestFactory::getInstance (const QString & pattern)
{
    QMap< QString, QSharedPointer<IServerRequest> >::iterator it;

    for (it = _requests.begin (); it != _requests.end (); ++it)
    {
        QRegExp regex (it.key ());

        if (regex.indexIn (pattern) != -1)
        {
            return it.value ();
        }
    }

    return QSharedPointer<IServerRequest> (NULL);
}

bool ServerRequestFactory::registerRequest (const QString & regularExpression, const QSharedPointer<IServerRequest> & request)
{
    if (_requests.contains(regularExpression))
    {
        return false;
    }

    _requests.insert (regularExpression, request);

    return true;
}
