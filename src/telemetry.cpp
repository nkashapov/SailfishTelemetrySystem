// telemetry.cpp
#include "telemetry.h"
#include "appevent.h"

#include <QDBusReply>
#include <QDBusMessage>
#include <QDBusInterface>

struct Telemetry::Impl
{
    const QString serviceName{"ru.sonarh.dbus.telemetry"};
    const QString path{"/ru/sonarh/dbus/telemetry"};
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
    auto interfaceName = "ru.buffer";
    auto methodName = "sendTelemetry";
    QDBusInterface interface(d->serviceName, d->path, interfaceName);

    if (interface.isValid())
    {
        interface.call(QDBus::Block, methodName, messageToSend);
    }
}
