#include "ServerLogger.h"
#include "FileAppender.h"
#include "ConsoleAppender.h"
#include "Configuration.h"

using namespace std;

ServerLogger::ServerLogger ()
{
    FileAppender * fileAppender = new FileAppender ();
    ConsoleAppender * consoleAppender = new ConsoleAppender ();

    fileAppender->setFileName (Configuration::loggingFilename);
    fileAppender->setFormat (Configuration::loggingFormat);
    consoleAppender->setFormat (Configuration::loggingFormat);

    Logger::registerAppender (fileAppender);
    Logger::registerAppender (consoleAppender);
}

ServerLogger::~ServerLogger ()
{
}

void ServerLogger::setup ()
{
    static ServerLogger serverLogger;
}
