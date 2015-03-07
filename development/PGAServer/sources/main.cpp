#include <QApplication>

#include "MainWindow.h"

#include "ServerLogger.h"

using namespace std;

int main (int argc, char * argv[])
{
    ServerLogger::setup ();

    QApplication app (argc, argv);

    MainWindow window;

    window.show ();

    return app.exec ();
}
