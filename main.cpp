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
#include "User.h"
#include "UserMenager.h"
#include "FileWithUsers.h"


using namespace std;


int main(){


    return 0;
}
