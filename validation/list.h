#ifndef LIST_H
#define LIST_H
#include <QString>
#include <QStringList>
#include "recordtable.h"

template <class T>
class List {
    T *head; //pointer on first node
    T *last; //pointer on last node
    int count; //amount nodes

    //Create new node in front of list
    //Input: -
    //Output: -
    void AddNodeInFront() {
        T *work;
        work = new T;
        work->SetPrevious(nullptr);

        if(head == nullptr) {
            work->SetNext(nullptr);
            last = work;

        } else {
            work->SetNext(head);
            head->SetPrevious(work);
        }

        head = work;
        count++;
    }

public:
    List() : head(nullptr), last(nullptr), count(0) {

    }

    ~List() {
        DeleteList();
    }

    //Create new node and add info in this node
    //Input: record table string
    //Output: -
    void AddNode(QString record) {
        AddNodeInFront();

        QStringList columns = record.split(',');
        head->SetDateTime(columns.value(0));
        head->SetName(columns.value(1));
        head->SetValue(columns.value(2));
    }

    //Create new node and add info in this node
    //Input: record table class item
    //Output: -
    void AddNode(T *record) {
        AddNodeInFront();

        head->SetDateTime(record->GetDateTimeForFile());
        head->SetName(record->GetName());
        head->SetValue(QString::number(record->GetValue()));
    }

    //Delete all items in list
    //Input: -
    //Output: -
    void DeleteList() {
        T *work;
        work = head;

        while(work != nullptr) {
            head = work->GetNext();
            delete work;
            work = head;
            count--;
        }
        head = work;
    }

    //Call function for sorting list T-type
    //Input: -
    //Output: -
    void SortList() {
        T::Sort(head);
    }

    //Return amount nodes
    //Input: -
    //Output: amount nodes
    int GetCount() {
        return count;
    }

    //Return required node
    //Input: number of node
    //Output: pointer on node
    T *GetNode(int n) {
        T *work;
        work = head;

        for (int i = 0; i < count; i++) {
            if (i == n) {
                return work;
            }
            work = work->GetNext();
        }
    }
};

#endif // LIST_H
