#ifndef _CONFIGURATION_H_
#define _CONFIGURATION_H_

#include <QString>

class Configuration
{
    public:
        static const QString loggingFilename;
        static const QString loggingFormat;
        static const QString lineSeparator;

    private:
        Configuration ();
        ~Configuration ();
};

#endif /* _CONFIGURATION_H_ */
