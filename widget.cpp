#include "widget.h"
#include "ui_widget.h"
#include "daemonipcdbus.h"

#include <QDebug>
#include <QProcess>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

/**
 * @brief Widget::setWiredSwitchEnable session dbus 方式打开有线网络设置
 * @param enabled
 *      - true  开启有线网络
 *      - false 关闭有线网络
 */
void Widget::setWiredSwitchEnable(bool enabled)
{
    DaemonIpcDbus *mDaemonIpcDbus;
    mDaemonIpcDbus = new DaemonIpcDbus();
    if (!mDaemonIpcDbus->daemonIsNotRunning()){
        qDebug() << "wiredSwitchEnable: " << enabled;
        mDaemonIpcDbus->setWiredSwitchEnable(enabled);
    }
}

/**
 * @brief Widget::openUkccNetwork 命令方式打开控制面板（设置）的网络设置页面
 */
void Widget::openUkccNetwork()
{
    char cmd[1024];

    memset(cmd, 0, 1024);

    sprintf(cmd, "%s", "/usr/bin/ukui-control-center -m netconnect ");

    system(cmd);
}

void Widget::on_radioButton_clicked(bool checked)
{
    qDebug() << "checked: " << checked;

    openUkccNetwork();
    setWiredSwitchEnable(checked);
}
