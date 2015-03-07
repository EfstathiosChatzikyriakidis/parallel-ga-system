#ifndef _MAIN_WINDOW_H_
#define _MAIN_WINDOW_H_

#include <QMainWindow>

class ServerManager;

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        explicit MainWindow (QWidget * parent = 0);

        ~MainWindow ();

    private slots:
        void on_startButton_clicked ();
        void on_stopButton_clicked ();

    private:
        QSharedPointer<Ui::MainWindow> _ui;

        QSharedPointer<ServerManager> _sm;
};

#endif /* _MAIN_WINDOW_H_ */
