#include <sstream>
#include "AuxiliaryMethods.h"

string AuxiliaryMethods::converteIntToString(int integer) {
    ostringstream ss;
    ss << integer;
    string str = ss.str();

    return str;
}

string AuxiliaryMethods::converteDoubleToString(double amount){
   string s = to_string(amount);
   for(int i=0; i<s.length(); i++){
    if(s[i] == '.' ){
        s = s.erase( i+3, s.length());
        break;
    }
   }

   return s;
}

string AuxiliaryMethods::getLine() {
    string in = "";
    getline(cin, in);

    return in;
}

int AuxiliaryMethods::converteStringToInt(string number) {
    int intNumber;
    istringstream iss(number);
    iss >> intNumber;

    return intNumber;
}

char AuxiliaryMethods::getChar() {
    string in = "";
    char sign  = {0};

    while (true) {
        getline(cin, in);

        if (in.length() == 1) {
            sign = in[0];
            break;
        }
        cout << "It is not single char. Try again." << endl;
    }

    return sign;
}

int AuxiliaryMethods::wczytajLiczbeCalkowita() {
    string wejscie = "";
    int liczba = 0;

    while (true) {
        getline(cin, wejscie);

        stringstream myStream(wejscie);
        if (myStream >> liczba)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }

    return liczba;
}

string AuxiliaryMethods::zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst) {
    if (!tekst.empty()) {
        transform(tekst.begin(), tekst.end(), tekst.begin(), ::tolower);
        tekst[0] = toupper(tekst[0]);
    }

    return tekst;
}

double AuxiliaryMethods::getDoubleTypeOfNumber() {
    bool isNumberCorrect = false;
    bool isThisDoubleType = false;
    double number = 0;
    string decimalPart = "";
    string in = "";

    while(!isNumberCorrect) {
        isNumberCorrect = true;
        isThisDoubleType = false;
        decimalPart = "";
        cin >> in;
        for(int i=0; i<in.length(); i++) {
            if(in[i]>47 && in[i]<58 && isThisDoubleType == true) decimalPart += in[i];
            else if(in[i]>47 && in[i]<58);
            else if((in[i] == 46 || in[i] == 44 )&& isThisDoubleType == false) isThisDoubleType = true;
            else if(in[i] == 46 && isThisDoubleType == true) isNumberCorrect = false;
            else isNumberCorrect = false;
        }
        if(decimalPart.length()>2) isNumberCorrect = false;
        else number = converteStringToInt(in)+(converteStringToInt(decimalPart)/pow(10, decimalPart.length()));

        if(isNumberCorrect == false) cout<< "Incorrect number. Try again: ";
    }
    return number;
}
