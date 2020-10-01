#ifndef DANDT_H
#define DANDT_H

#include <QObject>
#include <ctime>
#include <windows.h>
#include <sstream>

class dandt : public QObject
{
    Q_OBJECT
public:
    QString TDate, TTime;
    explicit dandt(QObject *parent = nullptr);


signals:

};

#endif // DANDT_H
