// telemetry.cpp
#include "dbusutil.h"
#include "telemetry.h"
#include <QDBusInterface>
#include <QDBusReply>
#include <QDBusMessage>
#include <QXmlStreamReader>
#include <QDBusInterface>
#include "appevent.h"
#include "appevents.cpp"

void Telemetry::sendMessage(QString messageToSend){
    QString serviceName = "ru.sonarh.dbus.telemetry";
    bool isSystemBus = false;
    QString path = "/ru/sonarh/dbus/telemetry";
    QString interfaceName = "ru.buffer";
    QString methodName = "sendTel";
    QList<QVariant> arguments = QList<QVariant>();
    arguments.append(QVariant(messageToSend));
    dDusConnection = isSystemBus ? QDBusConnection::systemBus() : QDBusConnection::sessionBus();
    QDBusInterface interface(serviceName, path, interfaceName, dDusConnection);
    interface.callWithArgumentList(QDBus::Block, methodName, DBusUtil::convertToDBusArguments(arguments, interface, methodName));
}

void Telemetry::sendOpen()
{
    sendMessage("Open!");
}

void Telemetry::sendClose()
{
    sendMessage("Close!");
}
void Telemetry::sendVal(QString newtext)
{
    sendMessage(newtext);
}
void Telemetry::sendEvent(AppEvent event)
{
    sendMessage(event.getName());
}
