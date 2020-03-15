#include "file.h"

File::File() {}

File::~File() {
    if (Input.is_open()) {
        Input.close();
    }
    if (Output.is_open()) {
        Output.close();
    }
}

//Read info from file
//Input: file name
//Output: -
void File::ReadFile(QString namefile) {
    string buffer;

    namefile.indexOf(".txt") != -1 ? Input.open(namefile.toStdString()) : Input.open(namefile.toStdString() + ".txt");

    if (Input.is_open()) {
        while (getline(Input, buffer)) {
            if (buffer[0] != '\0' && buffer[0] != ' ') {
                ListRecords.AddNode(QString::fromStdString(buffer));
            }
        }
        Input.close();

        ListRecords.SortList();
    }
}

//Write info in files
//Input: -
//Output: -
void File::WriteFile() {
    QString str;
    List<RecordTable> ListName;
    bool flag;
    int value = 0;

    //search unique names
    for (int i = 0; i < ListRecords.GetCount() - 1; i++) {
        flag = true;

        for (int n = 0; n < ListName.GetCount() - 1; n++) {
            if (ListName.GetNode(n)->GetName() == ListRecords.GetNode(i)->GetName()) {
                flag = false;
            }
        }

        if (flag) {
            ListName.AddNode(ListRecords.GetNode(i));
        }
    }

    //Write info in files
    for (int i = 0; i < ListRecords.GetCount() - 1; i++) {
        Output.open(ListRecords.GetNode(i)->GetName().toStdString() + ".txt", ios_base::app);

        if (Output.is_open()) {
            str = ListRecords.GetNode(i)->GetDateTimeForFile() + ", " + ListRecords.GetNode(i)->GetName() + ", " + QString::number(ListRecords.GetNode(i)->GetValue());

            Output << str.toStdString() << endl;
            Output.close();
        }
    }

    //Write sum values in files
    for (int n = 0; n < ListName.GetCount() - 1; n++) {
        for (int i = 0; i < ListRecords.GetCount() - 1; i++) {

            if (ListName.GetNode(n)->GetName() == ListRecords.GetNode(i)->GetName()) {
                value += ListRecords.GetNode(i)->GetValue();
            }
        }
        Output.open(ListName.GetNode(n)->GetName().toStdString() + ".txt", ios_base::app);

        if (Output.is_open()) {

            Output << "Sum values: " + QString::number(value).toStdString() << endl;
            Output.close();
        }
    }
}
