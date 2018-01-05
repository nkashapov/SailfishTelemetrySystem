// telemetry.cpp
#include "dbusutil.h"
#include "telemetry.h"
#include <QDBusInterface>
#include <QDBusReply>
#include <QDBusMessage>
#include <QXmlStreamReader>
#include <QDBusInterface>
#include "appevent.h"

namespace
{
    const QString serviceName{"ru.sonarh.dbus.telemetry"};
    const QString path{"/ru/sonarh/dbus/telemetry"};
}

struct Telemetry::Impl
{
    QString serviceName;
    QDBusConnection dBusConnection = QDBusConnection::systemBus();
};

Telemetry::Telemetry(QObject *parent) :
    QObject(parent),
    d(new Impl)
{
}

Telemetry::~Telemetry()
{
}

void Telemetry::sendOpen()
{
    sendMessage("Open!");
}

void Telemetry::sendClose()
{
    sendMessage("Close!");
}

void Telemetry::sendEvent(const AppEvent& event)
{
    sendMessage(event.getName());
}

void Telemetry::sendVal(const QString &newtext)
{
    sendMessage(newtext);
}

void Telemetry::sendMessage(const QString &messageToSend)
{
    bool isSystemBus = false;
    QString interfaceName = "ru.buffer";
    QString methodName = "sendTel";
    QList<QVariant> arguments = {messageToSend};
    d->dBusConnection = isSystemBus ? QDBusConnection::systemBus() : QDBusConnection::sessionBus();
    QDBusInterface interface(::serviceName, ::path, interfaceName, d->dBusConnection);
    interface.callWithArgumentList(QDBus::Block, methodName,
                                   DBusUtil::convertToDBusArguments(arguments, interface, methodName));
}

