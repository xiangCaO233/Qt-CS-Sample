#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class ServerMainWindow;
}

class MainServer;

class ServerMainWindow : public QMainWindow {
    Q_OBJECT

   public:
    explicit ServerMainWindow(QWidget *parent = nullptr);
    ~ServerMainWindow();

   private:
    Ui::ServerMainWindow *ui;
    MainServer *m_Mainserver{nullptr};

    void start(short port);
    void stop();
};

#endif  // MAINWINDOW_H
