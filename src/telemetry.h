#ifndef TELEMETRY_H
#define TELEMETRY_H

#include <QDBusInterface>
#include <QDBusReply>
#include <QDBusMessage>
#include <QXmlStreamReader>
#include "appevent.h"
// telemetry.h

#include <QObject>

class Telemetry : public QObject {
    Q_OBJECT
private:
    QString serviceName;
    QDBusConnection dDusConnection;
    Q_INVOKABLE void sendMessage(QString messageToSend);
public:
    Telemetry() : serviceName(""),dDusConnection(QDBusConnection::systemBus()) {}
    Q_INVOKABLE void sendOpen();
    Q_INVOKABLE void sendClose();
    Q_INVOKABLE void sendEvent(AppEvent event);
    Q_INVOKABLE void sendVal(QString newtext);
private slots:
signals:
};

#endif // TELEMETRY_H
