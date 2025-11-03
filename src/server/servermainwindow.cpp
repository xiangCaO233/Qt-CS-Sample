#include "servermainwindow.h"

#include "MainServer.h"
#include "ui_servermainwindow.h"

ServerMainWindow::ServerMainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::ServerMainWindow) {
    ui->setupUi(this);
    m_Mainserver = new MainServer(this);
}

ServerMainWindow::~ServerMainWindow() { delete ui; }

void ServerMainWindow::start(short port) { m_Mainserver->startServer(port); }

void ServerMainWindow::stop() { m_Mainserver->stopServer(); }
