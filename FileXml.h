#ifndef FILEXML_H
#define FILEXML_H
#include <fstream>
#include <iostream>

using namespace std;

class FileXml{
const string NAME_OF_FILE;

public:
FileXml(string name_of_file):NAME_OF_FILE(name_of_file){};
bool isFileEmpty();
string getFileName();
};
#endif
