#ifndef ISENSOR_H
#define ISENSOR_H
#include <QString>

class ISensor {

protected:
    QString type;
    int value;
    virtual bool Measure() = 0;

public:
    ISensor() {}
    virtual ~ISensor() {}

    virtual void SetTypeSensor(QString) = 0;
    virtual void SetValueSensor(int) = 0;

    virtual QString GetTypeSensor() = 0;
    virtual int GetValueSensor() = 0;
};

#endif // ISENSOR_H
