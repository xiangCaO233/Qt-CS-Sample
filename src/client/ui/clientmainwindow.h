#ifndef CLIENTMAINWINDOW_H
#define CLIENTMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class ClientMainWindow;
}

class StandardClient;

class ClientMainWindow : public QMainWindow {
    Q_OBJECT

   public:
    explicit ClientMainWindow(QWidget *parent = nullptr);
    ~ClientMainWindow();

   private slots:
    void on_connect_button_clicked();

    void on_disconnect_button_clicked();

   private:
    Ui::ClientMainWindow *ui;
    StandardClient *m_Client;
};

#endif  // CLIENTMAINWINDOW_H
