// include/User.h
#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
private:
    string username;
    string password;

public:
    User() = default;
    User(const string& username, const string& password);

    string getUsername() const;
    string getPassword() const;
};

#endif
