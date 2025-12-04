// include/AuthManager.h
#ifndef AUTH_MANAGER_H
#define AUTH_MANAGER_H

#include <string>
#include <vector>
#include "User.h"
using namespace std;

class AuthManager {
private:
    string usersFilePath;
    vector<User> users;

    void loadUsers();
    void saveUsers() const;

public:
    AuthManager(const string& filePath);

    bool signup(const string& username, const string& password);
    bool login(const string& username, const string& password, User& outUser);
};

#endif
