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

#ifndef DAEMONIPCDBUS_H
#define DAEMONIPCDBUS_H

/// Session Dbus Template 调用模板
//
/// 1. 演示麒麟操作系统有线网络 session dbus 控制

#define KYLIN_NETWORK_METHOD_NAME "setWiredSwitchEnable"
#define SERVICE_NAME_SIZE 30
#define KYLIN_NETWORK_SERVICE "com.kylin.network" // 对象名称 Bus Name
#define KYLIN_NETWORK_PATH "/com/kylin/network" // 对象路径
#define KYLIN_NETWORK_INTERFACE "com.kylin.network" // 接口

#include <QObject>
#include <QApplication>
#include <QCoreApplication>
#include <QDebug>
#include <QtDBus/QDBusConnection>
#include <QtDBus/QDBusConnectionInterface>
#include <QtDBus/QDBusMessage>
#include <QtDBus/QDBusReply>
#include <unistd.h>
#include <sys/types.h>

/**
 * @brief The DaemonIpcDbus class
 *
 * 使用方法:
 * @code
 *      DaemonIpcDbus *mDaemonIpcDbus;
 *      mDaemonIpcDbus = new DaemonIpcDbus();
 *      if (!mDaemonIpcDbus->daemonIsNotRunning()){
 *              bool wiredSwitchEnable = true;
 *              mDaemonIpcDbus->setWiredSwitchEnable(wiredSwitchEnable);
 *      }
 * @endcode
 */
class DaemonIpcDbus : public QObject
{
    Q_OBJECT
    // 定义Interface名称为com.scorpio.test.value
    // Q_CLASSINFO("D-Bus Interface", "com.scorpio.test.value")

public:
    DaemonIpcDbus() {}

public Q_SLOTS:

    int daemonIsNotRunning();
    void setWiredSwitchEnable(bool enable);
};

#endif // DAEMONIPCDBUS_H
