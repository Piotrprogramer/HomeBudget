#include "FileXml.h"


//FileXml::isFileEmpty(){};

using namespace std;

bool FileXml::isFileEmpty(){
    ifstream fileXml( NAME_OF_FILE.c_str(), ios::in);
    fileXml.seekg(0, ios::end);

    if (fileXml.tellg() == 0)
        return true;
    else
        return false;
}

string FileXml::getFileName(){
return NAME_OF_FILE;
};
