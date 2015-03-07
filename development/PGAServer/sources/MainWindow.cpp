#include <QDebug>

#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "ServerManager.h"
#include "ServerLogger.h"

using namespace std;

MainWindow::MainWindow (QWidget * parent) : QMainWindow (parent)
{
    _ui = QSharedPointer<Ui::MainWindow> (new Ui::MainWindow ());

    _ui->setupUi (this);

    setMaximumSize (width (), height ());

    _sm = QSharedPointer<ServerManager> (new ServerManager ());
}

MainWindow::~MainWindow ()
{
}

void MainWindow::on_startButton_clicked ()
{
    const QString host = _ui->hostEdit->text ();
    const QString port = _ui->portEdit->text ();

    try
    {
        _sm->setHost (host);
        _sm->setPort (port);

        _sm->start ();
    }
    catch (exception & e)
    {
        LOG_ERROR () << e.what ();
    }
}

void MainWindow::on_stopButton_clicked ()
{
    try
    {
        _sm->stop ();
    }
    catch (exception & e)
    {
        LOG_ERROR () << e.what ();
    }
}
