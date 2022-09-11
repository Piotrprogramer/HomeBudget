#include "UserMenager.h"


int UserMenager::mainMenu() {
    char choice;
    while(1) {
        cin.sync();
        system("cls");
        cout<<idLoggedUser<<endl;
        cout<<"1- Log in"<<endl<< "2- Sing up"<<endl<< "0- Exit application"<<endl<<"-------------------"<<endl;
        choice = AuxiliaryMethods::getChar();
        switch(choice) {
        case '1': {
            loggingUser();
            break;
        }
        case '2': {
            registerNewUser();
            break;
        }
        case '0': exit(0);
        }
    }

    loggingUser();
    return 0;
};

void UserMenager::loggingUser() {
    cin.sync();
    bool loginFound = false;
    string login = "", password = "";

    cout << endl << "Enter your login: ";
    login = AuxiliaryMethods::getLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end()) {
        if (itr -> getLogin() == login) {
            loginFound = true;
            for (int trialsNumber = 3; trialsNumber > 0; trialsNumber--) {
                cout<< "Trials remain: " << trialsNumber << endl << "Enter password: " ;
                password = AuxiliaryMethods::getLine();
                if (itr ->getPassword() == password) {
                    idLoggedUser = itr->getUserId();
                    cout << endl << "You logged in correctly." << endl << endl;
                    system("pause");

                    idLoggedUser = itr->getUserId();
                    break;
                }
                if(trialsNumber == 1) {
                    cout << "You entered 3 times wrong password." << endl;
                    system("pause");
                    break;
                }
            }
            break;
        }
        itr++;
    }
    if(!loginFound) {
        cout << "There is no user with entered login" << endl << endl;
        system("pause");
    }
}

vector <User> UserMenager::getUsers() {
    vector <User> users;

    CMarkup xml;
    bool fileExists = xml.Load( getFileName());

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem(getFileName());
    }

    xml.FindElem(); // ORDER element is root
    xml.IntoElem(); // inside ORDER

    while ( xml.FindElem("User") ) {
        int userId;
        string login;
        string password;
        string data;

        xml.FindChildElem(  );
        data = xml.GetChildData();
        userId = AuxiliaryMethods::converteStringToInt(data);
        lastUserId = userId;

        xml.FindChildElem(  );
        data = xml.GetChildData();
        login = data;

        xml.FindChildElem(  );
        data = xml.GetChildData();
        password = data;

        User user(userId,login,password);
        users.push_back(user);
    }
    return users;
};

User UserMenager::getNewUserData() {
    int userId;
    string login;
    string password;

    bool isAvailable = false;

    while(!isAvailable) {
        cout<<"Set username: ";
        cin>>login;
        isAvailable = checkUsernameAvailability(login);
        if(!isAvailable) cout<<"User name is already used. Try again."<<endl;
    }

    cout<<"Set password: ";
    cin>>password;

    userId = getNewUserId();
    User newUser(userId,login,password);

    return newUser;
};
/*
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
*/
int UserMenager::getIdLoggedUser() {
    return idLoggedUser;
}

bool UserMenager::checkUsernameAvailability(string login) {
    bool isAvailable = true;

    for (auto x : users) if(x.getLogin() == login) {
            isAvailable = false;
            break;
        }

    return isAvailable;
};

int UserMenager::getNewUserId() {
    if (users.empty() == true)
        return 1;
    else
        return ++lastUserId;
}

void UserMenager::saveUserToFile(User user) {
    CMarkup xml;
    bool fileExists = xml.Load( getFileName());

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem(getFileName());
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.getUserId());
    xml.AddElem("UserLogin", user.getLogin());
    xml.AddElem("Password", user.getPassword());

    xml.Save(getFileName());
    users.push_back(user);
};

void UserMenager::addUser() {
    User newUser = getNewUserData();
    saveUserToFile(newUser);
};

void UserMenager::displayAll() {
    for(auto x:users ) cout<<"Id: "<<x.getUserId()<<endl<<"user name: "<<x.getLogin()<<endl<<"Password: "<<x.getPassword()<<endl<<"----------------------"<<endl;
};




void UserMenager::registerNewUser() {
    User user = getNewUserData();

    users.push_back(user);
    saveUserToFile(user);

    cout << endl << "Registration completed successfully" << endl << endl;
    system("pause");
}



/*
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
*/

/*
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

*/
