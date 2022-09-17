#include "UserMenager.h"

void UserMenager::mainMenu() {
    char choice;
    while(idLoggedUser == 0) {
        cin.sync();
        system("cls");
        cout<<"1- Log in"<<endl;
        cout<<"2- Sing up"<<endl;
        cout<<"0- Exit application"<<endl;
        cout<<"====================="<<endl;
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
        case '0':
            exit(0);
        }
    }
};

void UserMenager::loggingUser() {
    cin.sync();
    bool loginFound = false;
    string login = "", password = "";

    cout << endl << "Enter your login: ";
    login = AuxiliaryMethods::getLine();

    vector <User>::iterator itr = fileWithUsers.begin();
    while (itr != fileWithUsers.end()) {
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

void UserMenager::logOutUser(){
    idLoggedUser = 0;
}

vector <User> UserMenager::getUsers() {
    vector <User> fileWithUsers;

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
        fileWithUsers.push_back(user);
    }
    return fileWithUsers;
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

int UserMenager::getIdLoggedUser() {
    return idLoggedUser;
}

bool UserMenager::checkUsernameAvailability(string login) {
    bool isAvailable = true;

    for (auto x : fileWithUsers) if(x.getLogin() == login) {
            isAvailable = false;
            break;
        }

    return isAvailable;
};

int UserMenager::getNewUserId() {
    if (fileWithUsers.empty() == true)
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
    fileWithUsers.push_back(user);
};

void UserMenager::addUser() {
    User newUser = getNewUserData();
    saveUserToFile(newUser);
};

void UserMenager::displayAll() {
    for(auto x:fileWithUsers ) cout<<"Id: "<<x.getUserId()<<endl<<"user name: "<<x.getLogin()<<endl<<"Password: "<<x.getPassword()<<endl<<"----------------------"<<endl;
};

void UserMenager::registerNewUser() {
    User user = getNewUserData();

    fileWithUsers.push_back(user);
    saveUserToFile(user);

    cout << endl << "Registration completed successfully" << endl << endl;
    system("pause");
}

void UserMenager::changePasswordLoggedUser() {
    cin.sync();
    vector<User> newFileWithUsers;

    string password;
    bool passwordChangedCorrectly = false;
    cout<<endl<<"Enter present password: ";
    password = AuxiliaryMethods::getLine();

    //vector <User>::iterator itr = fileWithUsers.begin();
    //while (itr != fileWithUsers.end())
    for(auto user: fileWithUsers){
        if(user.getPassword() == password && user.getUserId() == idLoggedUser) {
            cout<<endl<<"Enter new password: ";
            password = AuxiliaryMethods::getLine();

                //system("pause");
            //user.setPassword(password);
                // system("pause");
            //cout<<user.getLogin()<<endl;
                // system("pause");
            User newPasswordUser(user.getUserId(), user.getLogin(), password);
            newFileWithUsers.push_back(newPasswordUser);
            passwordChangedCorrectly = true;
        }
        else newFileWithUsers.push_back(user);
    }
    if(!passwordChangedCorrectly) {
        cout<<endl<<"You entered incorrect current password"<<endl;
        system("pause");
    }
    else {
        fileWithUsers.clear();
        fileWithUsers = newFileWithUsers;
        saveAllUsersToFile();
        cout<<"Password changed correctly "<<endl;
        system("pause");
    }
}

void UserMenager::saveAllUsersToFile() {
    CMarkup xml;
    xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
    xml.AddElem(getFileName());

    for(auto user: fileWithUsers){
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.getUserId());
    xml.AddElem("UserLogin", user.getLogin());
    xml.AddElem("Password", user.getPassword());
    xml.OutOfElem();
    xml.OutOfElem();
    }
    xml.Save(getFileName());
};
