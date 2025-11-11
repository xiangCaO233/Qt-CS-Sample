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

    // 日志框只读
    ui->logarea->setReadOnly(true);
}

ServerMainWindow::~ServerMainWindow() { delete ui; }

void ServerMainWindow::start(short port) { m_Mainserver->startServer(port); }

void ServerMainWindow::stop() { m_Mainserver->stopServer(); }

void ServerMainWindow::on_start_server_button_clicked() {
    if (!m_Mainserver->alive()) {
        auto port = ui->port_lineedit->text().toShort();
        m_Mainserver->startServer(port);
        ui->logarea->append(QString("服务器正在监听%1").arg(port));
    } else {
        ui->logarea->append("服务器正在监听中，请先停止");
    }
}

void ServerMainWindow::on_stop_server_button_clicked() {
    if (m_Mainserver->alive()) {
        m_Mainserver->stopServer();
    }
    ui->logarea->append("服务器已停止");
}
