#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainServer;

class ServerMainWindow : public QMainWindow {
    Q_OBJECT

   public:
    explicit ServerMainWindow(QWidget *parent = nullptr);
    ~ServerMainWindow();

    void start(short port);

   private:
    Ui::MainWindow *ui;
    MainServer *m_Mainserver{nullptr};
};

#endif  // MAINWINDOW_H
