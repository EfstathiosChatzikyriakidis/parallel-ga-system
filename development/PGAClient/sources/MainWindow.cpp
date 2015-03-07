#include "MainWindow.h"

#include "ui_MainWindow.h"

using namespace std;

MainWindow::MainWindow (QWidget * parent) : QMainWindow (parent)
{
    _ui = QSharedPointer<Ui::MainWindow> (new Ui::MainWindow ());

    _ui->setupUi (this);

    setMaximumSize (width (), height ());
}

MainWindow::~MainWindow ()
{
}
