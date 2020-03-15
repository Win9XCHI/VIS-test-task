#include "recordtable.h"

RecordTable::RecordTable() : name(""), value(0) {
}

RecordTable::~RecordTable() {
}

void RecordTable::SetDateTime(QString str) {
    DateTime.SetDateTime(str);
}

void RecordTable::SetName(QString str) {
    name = str;
}

void RecordTable::SetValue(QString str) {
    value = str.toInt();
}

void RecordTable::SetNext(RecordTable *pointer) {
    next = pointer;
}

void RecordTable::SetPrevious(RecordTable *pointer) {
    previous = pointer;
}

RecordTable *RecordTable::GetNext() {
    return next;
}

RecordTable *RecordTable::GetPrevious() {
    return previous;
}

QString RecordTable::GetDateTimeForFile() {
    return DateTime.GetDateTime();
}

DateAndTime RecordTable::GetDateTime() {
    return DateTime;
}

QString RecordTable::GetName() {
    return name;
}

int RecordTable::GetValue() {
    return value;
}

//Static function for sorting list
//Input: pointer on head of list
//Output: -
void RecordTable::Sort(RecordTable *head) {
    RecordTable *tmp, *a, x;
    bool flag = true;

    while(flag) {
       tmp = head;
       a = tmp->GetNext();
       flag = false;

       while(a != nullptr) {

          if(tmp->GetDateTime() > a->GetDateTime()) {
              x.SetDateTime(tmp->GetDateTimeForFile());
              x.SetName(tmp->GetName());
              x.SetValue(QString::number(tmp->GetValue()));

              tmp->SetDateTime(a->GetDateTimeForFile());
              tmp->SetName(a->GetName());
              tmp->SetValue(QString::number(a->GetValue()));

              a->SetDateTime(x.GetDateTimeForFile());
              a->SetName(x.GetName());
              a->SetValue(QString::number(x.GetValue()));

              flag = true;
          }

          tmp = tmp->GetNext();
          a = a->GetNext();
        }
     }
}
