#include "UserMenager.h"
/*
void UserMenager::rejestracjaUzytkownika() {
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

User UserMenager::podajDaneNowegoUzytkownika() {
    User user;
    user.setUserId(getNewIdForUser());
    string login;
    do {
        cout << endl << "Set login: ";
        cin >> login;
        user.setLogin(login);
    } while (czyIstniejeLogin(user.pobierzLogin()) == true);

    string password;
    cout << "Set password: ";
    cin >> password;
    user.setPassword(password);

    return user;
}

int UserMenager::getNewIdForUser() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}

bool UserMenager::czyIstniejeLogin(string login) {
    for(int i=0; i<uzytkownicy.size(); i++) {
        if(uzytkownicy[i].pobierzLogin() == login ) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UserMenager::wczytajUzytkownikowZPliku() {
    uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
}

int UserMenager::logowanieUzytkownika() {
    cin.sync();
    bool znalezionoLogin = false;
    string login = "", haslo = "";

    cout << endl << "Podaj login: ";
    login = metodyPomocnicze.wczytajLinie();
    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    while (itr != uzytkownicy.end()) {
        if (itr -> pobierzLogin() == login) {
            znalezionoLogin = true;
            for (int iloscProb = 3; iloscProb > 0; iloscProb--) {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = metodyPomocnicze.wczytajLinie();
                if (itr ->pobierzHaslo() == haslo) {
                    idZalogowanegoUzytkownika = itr->pobierzId();
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");

                    return  itr->pobierzId();
                }
                if(iloscProb == 1) {
                    cout << "Wprowadzono 3 razy bledne haslo." << endl;
                    system("pause");
                    break;
                }
            }
            break;
        }
        itr++;
    }
    if(!znalezionoLogin) {
        cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
        system("pause");

        return 0;
    }
}

void UserMenager::zmienHasloZalogowanegoUzytkownika() {
    MetodyPomocnicze metodyPomocnicze;
    cin.sync();
    string haslo;
    bool hasloPoprawnieZmienione=false;
    cout<<endl<<"Podaj obecne haslo: ";
    haslo = metodyPomocnicze.wczytajLinie();

    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    while (itr != uzytkownicy.end()) {
        if(itr->pobierzHaslo() == haslo && itr->pobierzId() == idZalogowanegoUzytkownika) {
            cout<<endl<<"Podaj nowe haslo: ";
            haslo = metodyPomocnicze.wczytajLinie();
            itr->ustawHaslo(haslo);
            cout<<itr->pobierzLogin()<<endl;
            cout<<"Haslo zmienione poprawnie "<<endl;
            hasloPoprawnieZmienione = true;
            plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
            system("pause");
        }
        itr++;
    }
    if(!hasloPoprawnieZmienione) {
        cout<<endl<<"Podales nieprawidlowe obecne haslo "<<endl;
        system("pause");
    }
}

void UserMenager::wylogujUzytkownika() {
    idZalogowanegoUzytkownika = 0;
}

int UserMenager::pobierzIdZalogowanegoUzytkownika() {
    return idZalogowanegoUzytkownika;
}
*/
