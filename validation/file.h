#ifndef FILE_H
#define FILE_H
#include "list.h"
#include <fstream>

using namespace std;

class File {
    ifstream Input;
    ofstream Output;
    List<RecordTable> ListRecords;

public:
    File();
    ~File();

    //Read info from file
    //Input: file name
    //Output: -
    void ReadFile(QString);

    //Write info in files
    //Input: -
    //Output: -
    void WriteFile();
};

#endif // FILE_H
