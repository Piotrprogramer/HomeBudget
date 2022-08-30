#include <iostream>
#include "Markup.h"
#include "User.h"
#include "Accountant.h"

using namespace std;

int _main()
{

    return 0;
}


#include "FileWithIncomes.h"
#include "Income.h"
#include "Calendar.h"
#include "Markup.h"
//#include <span class="code-string">"Markup.h"</span>

int main()
{
    FileWithIncomes fileWithIncomes("fileWithIncomes.xml",707);
    fileWithIncomes.getVectorWithIncomesOfDateRange();

    return 0;
}

