#ifndef APPEVENT_H
#define APPEVENT_H

#include <QObject>

class AppEvent : public QObject
{
    Q_OBJECT

public:
    explicit AppEvent(const QString &input, QObject *parent = nullptr);
    QString getName() const;

private:
    QString eventName;
};

#endif // APPEVENT_H
