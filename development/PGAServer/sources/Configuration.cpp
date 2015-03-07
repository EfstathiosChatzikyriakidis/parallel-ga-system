#include "Configuration.h"

using namespace std;

Configuration::Configuration ()
{
}

Configuration::~Configuration ()
{
}

const QString Configuration::lineSeparator = "\n";

const QString Configuration::loggingFilename = "logging.txt";

const QString Configuration::loggingFormat = "[%-7l] %t{yyyy-MM-dd, HH:mm:ss.zzz} <%C> %m" + Configuration::lineSeparator;
