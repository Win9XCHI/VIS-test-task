#include "dateandtime.h"

DateAndTime::DateAndTime() : Day(0), Month(0), Year(0), Hours(0), Minutes(0) {
}

DateAndTime::DateAndTime(QString str) {
    SetDateTime(str);
}

DateAndTime::~DateAndTime() {
}

//Setting attributes
//Input: date and time string
//Output: -
void DateAndTime::SetDateTime(QString str) {
    QStringList Date_and_time = str.split(' ');
    QStringList Date = Date_and_time.value(0).split(".");
    QStringList Time = Date_and_time.value(1).split(":");

    Day = Date.value(0).toInt();
    Month = Date.value(1).toInt();
    Year = Date.value(2).toInt();
    Hours = Time.value(0).toInt();
    Minutes = Time.value(1).toInt();
}

//Return date and time string
//Input: -
//Output: date and time string
QString DateAndTime::GetDateTime() {
    QString str = QString::number(Day) + "." + QString::number(Month) + "." + QString::number(Year) + " " + QString::number(Hours) + ":";
    if (Minutes < 10) {
        str += "0" + QString::number(Minutes);
    } else {
        str += QString::number(Minutes);
    }

    return str;
}

int DateAndTime::GetHours() {
    return Hours;
}

int DateAndTime::GetMinutes() {
    return Minutes;
}

int DateAndTime::GetDay() {
    return Day;
}

int DateAndTime::GetMonth() {
    return Month;
}

int DateAndTime::GetYear() {
    return Year;
}

bool operator> (const DateAndTime &Ob1, const DateAndTime &Ob2) {
    if (Ob1.Year > Ob2.Year) {
        return true;
    }
    if (Ob1.Year != Ob2.Year) {
        return false;
    }

    if (Ob1.Month > Ob2.Month) {
        return true;
    }
    if (Ob1.Month != Ob2.Month) {
        return false;
    }

    if (Ob1.Day > Ob2.Day) {
        return true;
    }
    if (Ob1.Day != Ob2.Day) {
        return false;
    }

    if (Ob1.Hours > Ob2.Hours) {
        return true;
    }
    if (Ob1.Hours != Ob2.Hours) {
        return false;
    }

    if (Ob1.Minutes > Ob2.Minutes) {
        return true;
    }
    if (Ob1.Minutes != Ob2.Minutes) {
        return false;
    }

    return false;
}

bool operator< (const DateAndTime &Ob1, const DateAndTime &Ob2) {
    if (Ob1.Year < Ob2.Year) {
        return true;
    }
    if (Ob1.Year != Ob2.Year) {
        return false;
    }

    if (Ob1.Month < Ob2.Month) {
        return true;
    }
    if (Ob1.Month != Ob2.Month) {
        return false;
    }

    if (Ob1.Day < Ob2.Day) {
        return true;
    }
    if (Ob1.Day != Ob2.Day) {
        return false;
    }

    if (Ob1.Hours < Ob2.Hours) {
        return true;
    }
    if (Ob1.Hours != Ob2.Hours) {
        return false;
    }

    if (Ob1.Minutes < Ob2.Minutes) {
        return true;
    }
    if (Ob1.Minutes != Ob2.Minutes) {
        return false;
    }

    return false;
}

bool operator== (const DateAndTime &Ob1, const DateAndTime &Ob2) {
    if (Ob1.Year != Ob2.Year) {
        return false;
    }

    if (Ob1.Month != Ob2.Month) {
        return false;
    }

    if (Ob1.Day != Ob2.Day) {
        return false;
    }

    if (Ob1.Hours != Ob2.Hours) {
        return false;
    }

    if (Ob1.Minutes != Ob2.Minutes) {
        return false;
    }

    return true;
}

DateAndTime& DateAndTime::operator= ( DateAndTime right ) {
    Year = right.GetYear();
    Month = right.GetMonth();
    Day = right.GetDay();
    Hours = right.GetHours();
    Minutes = right.GetMinutes();
    return *this ;
}
