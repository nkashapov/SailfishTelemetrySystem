#include "appevent.h"

AppEvent::AppEvent(const QString &input, QObject *parent) :
    QObject(parent)
{
    eventName = input;
}

QString AppEvent::getName() const
{
    return eventName;
}
