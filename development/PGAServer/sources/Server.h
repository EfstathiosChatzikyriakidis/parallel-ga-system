#ifndef _SERVER_H_
#define _SERVER_H_

#include <QTcpSocket>
#include <QTcpServer>
#include <QSet>

class ServerActionFactory;
class ServerRequestFactory;
class ServerBestRequest;
class ServerBestAction;

class Server : public QTcpServer
{
        Q_OBJECT

        public:
            Server ();
            ~Server ();

            unsigned short getPort ();
            QHostAddress getHost ();

            void setPort (const unsigned short & port);
            void setHost (const QHostAddress & host);

            void broadcast (const QTcpSocket & sender, const QString & message);

            void closeConnections ();

        private slots:
            void readyRead ();
            void disconnected ();

        protected:
            void incomingConnection (const int socketDescriptor);

        private:
            QSet<QTcpSocket *> _clients;

            QHostAddress _host;
            unsigned short _port;
};

#endif /* _SERVER_H_ */
