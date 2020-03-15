#ifndef DATEANDTIME_H
#define DATEANDTIME_H
#include <QString>
#include <QStringList>

class DateAndTime {

    int Day;
    int Month;
    int Year;
    int Hours;
    int Minutes;

public:
    DateAndTime();
    DateAndTime(QString);
    ~DateAndTime();

    friend bool operator> (const DateAndTime &, const DateAndTime &);
    friend bool operator< (const DateAndTime &, const DateAndTime &);
    friend bool operator== (const DateAndTime &, const DateAndTime &);
    DateAndTime& operator= ( DateAndTime );

    //Setting attributes
    //Input: date and time string
    //Output: -
    void SetDateTime(QString);

    //Return date and time string
    //Input: -
    //Output: date and time string
    QString GetDateTime();

    int GetHours();
    int GetMinutes();
    int GetDay();
    int GetMonth();
    int GetYear();

};

#endif // DATEANDTIME_H
