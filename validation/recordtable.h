#ifndef RECORDTABLE_H
#define RECORDTABLE_H
#include "dateandtime.h"
#include <QString>

class RecordTable {
    DateAndTime DateTime;
    QString name;
    int value;

    RecordTable *next; //pointer on next node
    RecordTable *previous; //pointer on previous node

public:

    RecordTable();
    ~RecordTable();

    //Static function for sorting list
    //Input: pointer on head of list
    //Output: -
    static void Sort(RecordTable*);

    void SetDateTime(QString);
    void SetName(QString);
    void SetValue(QString);
    void SetNext(RecordTable *);
    void SetPrevious(RecordTable *);

    RecordTable *GetNext();
    RecordTable *GetPrevious();
    DateAndTime GetDateTime();
    QString GetDateTimeForFile();
    QString GetName();
    int GetValue();
};

#endif // RECORDTABLE_H
