#ifndef TELEMETRY_H
#define TELEMETRY_H

#include <QObject>

class AppEvent;

class Telemetry : public QObject
{
    Q_OBJECT

public:
    Telemetry(QObject *parent = nullptr);
    ~Telemetry();

    Q_INVOKABLE void sendOpen();
    Q_INVOKABLE void sendClose();
    Q_INVOKABLE void sendEvent(const AppEvent& event);
    Q_INVOKABLE void sendVal(const QString& newtext);

private:
    Q_INVOKABLE void sendMessage(const QString &messageToSend);

    struct Impl;
    const QScopedPointer<Impl> d;
};

#endif // TELEMETRY_H
