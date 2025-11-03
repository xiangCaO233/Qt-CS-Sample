#include "servermainwindow.h"

#include <qvalidator.h>

#include "../MainServer.h"
#include "ui_servermainwindow.h"

ServerMainWindow::ServerMainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::ServerMainWindow) {
    ui->setupUi(this);
    m_Mainserver = new MainServer(this);

    // 端口输入限制
    ui->port_lineedit->setValidator(
        new QIntValidator(0, 25565, ui->port_lineedit));
}

ServerMainWindow::~ServerMainWindow() { delete ui; }

void ServerMainWindow::start(short port) { m_Mainserver->startServer(port); }

void ServerMainWindow::stop() { m_Mainserver->stopServer(); }
