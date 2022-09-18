#include <iostream>
#include "HomeBudget.h"

using namespace std;

int main(){
    HomeBudget homeBudget("FileWithUsers.xml", "fileWithIncomes.xml", "fileWithExpenses.xml");
    return 0;
}
