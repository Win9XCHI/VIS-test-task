#ifndef PRESSURE_H
#define PRESSURE_H
#include "isensor.h"

class Pressure : public ISensor {
    bool Measure() override {
        //Measure
        //value = ...
        return true;
    }

public:
    Pressure() {}
    virtual ~Pressure() {}

    void SetTypeSensor(QString str) override {
        type = str;
    }

    void SetValueSensor(int i) override {
        value = i;
    }

    virtual QString GetTypeSensor() override {
        return type;
    }

    virtual int GetValueSensor() override {
        return value;
    }
};

#endif // PRESSURE_H
