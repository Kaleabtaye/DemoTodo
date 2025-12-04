// include/App.h
#ifndef APP_H
#define APP_H

#include "AuthManager.h"
#include "TodoManager.h"
#include "User.h"

class App {
private:
    AuthManager auth;

    void showMainMenu();
    void showTodoMenu(const User& user);

public:
    App(const string& usersFilePath);
    void run();
};

#endif
