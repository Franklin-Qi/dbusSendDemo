/*
 * Copyright (C) 2022, KylinSoft Co., Ltd.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "daemonipcdbus.h"

int DaemonIpcDbus::daemonIsNotRunning()
{
    char service_name[SERVICE_NAME_SIZE];

    memset(service_name, 0, SERVICE_NAME_SIZE);
    snprintf(service_name, SERVICE_NAME_SIZE, "%s", KYLIN_NETWORK_SERVICE);

    QDBusConnection conn = QDBusConnection::sessionBus();
    if (!conn.isConnected())
        return -1;

    QDBusReply<QString> reply = conn.interface()->call("GetNameOwner", service_name);

    return reply.value() == "";
}

/**
 * @brief DaemonIpcDbus::setWiredSwitchEnable 切换有线网络
 * @param enable
 *      - true 开启有线网络
 *      - false 关闭有线网络
 */
void DaemonIpcDbus::setWiredSwitchEnable(bool enable)
{
    qDebug() << Q_FUNC_INFO << enable;
    bool ret= false;

    char service_name[SERVICE_NAME_SIZE];
    memset(service_name, 0, SERVICE_NAME_SIZE);
    snprintf(service_name, SERVICE_NAME_SIZE, "%s", KYLIN_NETWORK_SERVICE);

    // 用来构造一个在D-Bus上传递的Message
    QDBusMessage m = QDBusMessage::createMethodCall(QString(service_name),KYLIN_NETWORK_PATH,KYLIN_NETWORK_INTERFACE, KYLIN_NETWORK_METHOD_NAME);
    m << enable; // 给QDBusMessage增加一个参数;这是一种比较友好的写法，也可以用setArguments来实现

    QDBusMessage response = QDBusConnection::sessionBus().call(m); // 发送Message

    if (response.type()== QDBusMessage::ReplyMessage) {
        // 判断Method是否被正确返回, QDBusMessage的arguments不仅可以用来存储发送的参数，也用来存储返回值;
        // ret = response.arguments().at(0).toBool();

    } else {
        qDebug()<<"setWiredSwitchEnable In fail!\n";
    }
}

