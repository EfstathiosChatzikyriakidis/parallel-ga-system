#ifndef _SERVER_LOGGER_H_
#define _SERVER_LOGGER_H_

#include "Logger.h"

class ServerLogger
{
    public:
        static void setup ();

        ~ServerLogger ();

    private:
        ServerLogger ();
};

#endif /* _SERVER_LOGGER_H_ */
