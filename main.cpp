#include <iostream>
#include "Markup.h"
#include "User.h"

#include "FileWithIncomes.h"

using namespace std;


int fileWithIncomes_main()
{
    FileWithIncomes fileWithIncomes("fileWithIncomes.xml",707);
    vector <Income> incomes;
    incomes = fileWithIncomes.getVectorWithIncomesOfDateRange();

for ( int i = 0; i < incomes.size(); i++ ) {
     cout << incomes[ i ] .getDate()<<"    "<<incomes[ i ].getAmount()<<"   "<<incomes[i].getIncomeReason()<<endl;// = i;
}
    sort(incomes.begin(), incomes.end());

    cout << "Sorted \n";
    for (auto x : incomes) cout << x.getDate()<<"    " << x.getAmount()<<"   "<<x.getIncomeReason()<<endl;// = i;

    return 0;
}


#include <iostream>
#include "HomeBudget.h"


using namespace std;

int homeBudget_main(){
    HomeBudget homeBudget("FileWithUsers.xml", "fileWithIncomes.xml", "fileWithExpenses.xml");



    return 0;
}

#include <iostream>
#include "Calendar.h"


#include <ctime>
#include <iostream>



using namespace std;

int main(){
    //Calendar calendar;
    //tm date = calendar.getCurrentDate() ;
   // date = calendar.getCurrentDate() ;
    cout<< Calendar::getCurrentMonth()<<endl;


    return 0;
}
