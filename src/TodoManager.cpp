// src/TodoManager.cpp
#include "TodoManager.h"
#include <fstream>
#include <sstream>
#include <iostream>

TodoManager::TodoManager(const string& filePath)
    : filePath(filePath), nextId(1) {
    loadFromFile();
}

void TodoManager::loadFromFile() {
    todos.clear();
    ifstream in(filePath);
    if (!in.is_open()) {
        return; // no file yet, user has no todos
    }

    string line;
    int maxId = 0;

    while (getline(in, line)) {
        stringstream ss(line);
        string idStr, text, doneStr;
        if (getline(ss, idStr, '|') &&
            getline(ss, text, '|') &&
            getline(ss, doneStr)) {

            int id = stoi(idStr);
            bool done = (doneStr == "1");
            todos.emplace_back(id, text, done);
            if (id > maxId) maxId = id;
        }
    }
    nextId = maxId + 1;
}

void TodoManager::saveToFile() const {
    ofstream out(filePath, ios::trunc);
    for (const auto& t : todos) {
        out << t.getId() << "|" << t.getText() << "|" << (t.isDone() ? "1" : "0") << "\n";
    }
}

void TodoManager::listTodos() const {
    if (todos.empty()) {
        cout << "No todos yet.\n";
        return;
    }
    cout << "Your TODOs:\n";
    for (const auto& t : todos) {
        cout << t.getId() << ". [" << (t.isDone() ? "x" : " ") << "] " 
             << t.getText() << "\n";
    }
}

void TodoManager::addTodo(const string& text) {
    todos.emplace_back(nextId++, text, false);
    saveToFile();
}

bool TodoManager::updateTodo(int id, const string& newText) {
    for (auto& t : todos) {
        if (t.getId() == id) {
            t.setText(newText);
            saveToFile();
            return true;
        }
    }
    return false;
}

bool TodoManager::toggleDone(int id) {
    for (auto& t : todos) {
        if (t.getId() == id) {
            t.setDone(!t.isDone());
            saveToFile();
            return true;
        }
    }
    return false;
}

bool TodoManager::deleteTodo(int id) {
    for (size_t i = 0; i < todos.size(); ++i) {
        if (todos[i].getId() == id) {
            todos.erase(todos.begin() + i);
            saveToFile();
            return true;
        }
    }
    return false;
}
