#include "FileWithIncomes.h"


vector <Income> FileWithIncomes::loadIncomeFromFile(){};

void FileWithIncomes::saveIncomesToFile(){

    CMarkup xml;

    bool fileExists = xml.Load( getFileName());

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem(getFileName());
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", "2");
    xml.AddElem("Login", "bartek");
    xml.AddElem("Password", "456");

    xml.Save(getFileName());

};
