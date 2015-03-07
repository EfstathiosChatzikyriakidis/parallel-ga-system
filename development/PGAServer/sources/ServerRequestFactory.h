#ifndef _SERVER_REQUEST_FACTORY_H_
#define _SERVER_REQUEST_FACTORY_H_

#include <QSharedPointer>
#include <QRegExp>
#include <QMap>

class IServerRequest;

class ServerRequestFactory
{
    private:
        ServerRequestFactory ();
        ~ServerRequestFactory ();

        static QMap< QString, QSharedPointer<IServerRequest> > _requests;

    public:
        static QSharedPointer<IServerRequest> getInstance (const QString & pattern);

        static bool registerRequest (const QString & regularExpression, const QSharedPointer<IServerRequest> & request);
};

#endif /* _SERVER_REQUEST_FACTORY_H_ */
