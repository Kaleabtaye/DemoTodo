// src/AuthManager.cpp
#include "AuthManager.h"
#include <fstream>
#include <sstream>
#include <iostream>

AuthManager::AuthManager(const string& filePath)
    : usersFilePath(filePath) {
    loadUsers();
}

void AuthManager::loadUsers() {
    users.clear();
    ifstream in(usersFilePath);
    if (!in.is_open()) {
        // file might not exist yet, no problem
        return;
    }
    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        string username, password;
        if (getline(ss, username, ',') && getline(ss, password)) {
            users.emplace_back(username, password);
        }
    }
}

void AuthManager::saveUsers() const {
    ofstream out(usersFilePath, ios::trunc);
    for (const auto& user : users) {
        out << user.getUsername() << "," << user.getPassword() << "\n";
    }
}

bool AuthManager::signup(const string& username, const string& password) {
    for (const auto& u : users) {
        if (u.getUsername() == username) {
            return false; // username already exists
        }
    }
    users.emplace_back(username, password);
    saveUsers();
    return true;
}

bool AuthManager::login(const string& username, const string& password, User& outUser) {
    for (const auto& u : users) {
        if (u.getUsername() == username && u.getPassword() == password) {
            outUser = u;
            return true;
        }
    }
    return false;
}
