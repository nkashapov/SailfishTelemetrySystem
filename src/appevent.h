#ifndef APPEVENT_H
#define APPEVENT_H

#include <QObject>
#include <QException>

class AppEvent : public QObject
{
    Q_OBJECT
private:
    QString eventName;
public:
    explicit AppEvent(QString input){
        eventName = input;
    }
    explicit AppEvent(std::exception &e){
        eventName = QString(e);
    }
    QString getName(){
        return eventName();
    }


signals:

public slots:
};

#endif // APPEVENT_H
