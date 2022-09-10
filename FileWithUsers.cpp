#include "FileWithUsers.h"

vector <User> FileWithUsers::getUsers(){
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

User FileWithUsers::getNewUserData(){
    int userId;
    string login;
    string password;

    bool isAvailable = false;

    while(!isAvailable){
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

bool FileWithUsers::checkUsernameAvailability(string login){
    bool isAvailable = true;

    for (auto x : users) if(x.getLogin() == login) {
       isAvailable = false;
       break;
    }

    return isAvailable;
};

int FileWithUsers::getNewUserId() {
    if (users.empty() == true)
        return 1;
    else
        return ++lastUserId;
}

void FileWithUsers::saveUserToFile(User user){
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

void FileWithUsers::addUser(){
    User newUser = getNewUserData();
    saveUserToFile(newUser);
};

void FileWithUsers::displayAll(){
    for(auto x:users ) cout<<"Id: "<<x.getUserId()<<endl<<"user name: "<<x.getLogin()<<endl<<"Password: "<<x.getPassword()<<endl<<"----------------------"<<endl;
};


