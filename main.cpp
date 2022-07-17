#include <iostream>
#include "Markup.h"
#include "User.h"
#include "Accountant.h"

using namespace std;

int _main()
{

    CMarkup xml;

    bool fileExists = xml.Load( "users.xml" );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", "2");
    xml.AddElem("Login", "bartek");
    xml.AddElem("Password", "456");

    xml.Save("users.xml");

    return 0;
}

#include "FileWithIncomes.h"
int main()
{
    FileWithIncomes fileWithIncomes("fileWithIncomes.xml");
    cout<< fileWithIncomes.isFileEmpty()<<endl;
    fileWithIncomes.saveIncomesToFile();

    return 0;
}

#include "Income.h"
int Income_main()
{
    Income income(10,500,200,03,185);
    income.display();

    income.setData(0,1,1);
    income.setIncome(2000);
    income.display();

    return 0;
}
