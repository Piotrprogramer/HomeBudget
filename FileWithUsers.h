/*#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Markup.h"
#include "FileXml.h"
#include "User.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithUsers :public FileXml{
    int lastUserId=1;
    vector <User> users;
    vector <User> getUsers();
    User getNewUserData();
    int getNewUserId();
    bool checkUsernameAvailability(string login);
    void saveUserToFile(User user);

public:
    FileWithUsers(string FILENAMEWITHUSERS):  FileXml(FILENAMEWITHUSERS) {
    users = getUsers();
    };

    void addUser();

    void displayAll();
};
#endif
*/
