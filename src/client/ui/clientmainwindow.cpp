#include "clientmainwindow.h"

#include "../StandardClient.h"
#include "ui_clientmainwindow.h"

ClientMainWindow::ClientMainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::ClientMainWindow) {
    ui->setupUi(this);

    m_Client = new StandardClient(this);

    auto *validator = new QIntValidator(ui->port_lineEdit);
    validator->setRange(0, 25565);
    ui->port_lineEdit->setValidator(validator);

    // 用于匹配 IPv4 地址的正则表达式
    // 这个表达式匹配 0.0.0.0 到 255.255.255.255
    auto ipv4Range = QString("(?:[0-1]?[0-9]?[0-9]|2[0-4][0-9]|25[0-5])");
    QRegularExpression ipv4Regex("^" + ipv4Range + "\\." + ipv4Range + "\\." +
                                 ipv4Range + "\\." + ipv4Range + "$");

    // 创建验证器并将其设置给 server_lineEdit
    auto *ipv4Validator =
        new QRegularExpressionValidator(ipv4Regex, ui->server_lineEdit);

    ui->server_lineEdit->setValidator(ipv4Validator);
}

ClientMainWindow::~ClientMainWindow() { delete ui; }

void ClientMainWindow::on_connect_button_clicked() {
    auto hostnamne = ui->server_lineEdit->text();
    auto port = ui->port_lineEdit->text().toShort();
    m_Client->connectToServer(hostnamne, port);
}

void ClientMainWindow::on_disconnect_button_clicked() {
    m_Client->disconnectFromServer();
}
