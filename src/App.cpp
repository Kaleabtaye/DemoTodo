// src/App.cpp
#include "App.h"
#include <iostream>

App::App(const string& usersFilePath)
    : auth(usersFilePath) {}

void App::run() {
    while (true) {
        showMainMenu();
    }
}

void App::showMainMenu() {
    cout << "\n=== TODO APP ===\n";
    cout << "1. Login\n";
    cout << "2. Signup\n";
    cout << "3. Exit\n";
    cout << "Choose: ";

    int choice;
    cin >> choice;

    if (choice == 1) {
        string username, password;
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        User user;
        if (auth.login(username, password, user)) {
            cout << "Login successful.\n";
            showTodoMenu(user);
        } else {
            cout << "Invalid credentials.\n";
        }
    } else if (choice == 2) {
        string username, password;
        cout << "Choose username: ";
        cin >> username;
        cout << "Choose password: ";
        cin >> password;

        if (auth.signup(username, password)) {
            cout << "Signup successful. You can now login.\n";
        } else {
            cout << "Username already taken.\n";
        }
    } else if (choice == 3) {
        cout << "Goodbye!\n";
        exit(0);
    } else {
        cout << "Invalid choice.\n";
    }
}

void App::showTodoMenu(const User& user) {
    // file name is based on username
    string filePath = "data/todos_" + user.getUsername() + ".txt";
    TodoManager manager(filePath);

    while (true) {
        cout << "\n=== TODO MENU (" << user.getUsername() << ") ===\n";
        cout << "1. List todos\n";
        cout << "2. Add todo\n";
        cout << "3. Update todo text\n";
        cout << "4. Toggle done/undone\n";
        cout << "5. Delete todo\n";
        cout << "6. Logout\n";
        cout << "Choose: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            manager.listTodos();
        } else if (choice == 2) {
            cout << "Enter todo text: ";
            cin.ignore();
            string text;
            getline(cin, text);
            manager.addTodo(text);
        } else if (choice == 3) {
            int id;
            cout << "Enter todo id to update: ";
            cin >> id;
            cin.ignore();
            cout << "New text: ";
            string text;
            getline(cin, text);
            if (!manager.updateTodo(id, text))
                cout << "Todo not found.\n";
        } else if (choice == 4) {
            int id;
            cout << "Enter todo id to toggle: ";
            cin >> id;
            if (!manager.toggleDone(id))
                cout << "Todo not found.\n";
        } else if (choice == 5) {
            int id;
            cout << "Enter todo id to delete: ";
            cin >> id;
            if (!manager.deleteTodo(id))
                cout << "Todo not found.\n";
        } else if (choice == 6) {
            cout << "Logging out...\n";
            break;
        } else {
            cout << "Invalid choice.\n";
        }
    }
}
