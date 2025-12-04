// include/TodoManager.h
#ifndef TODO_MANAGER_H
#define TODO_MANAGER_H

#include <vector>
#include <string>
#include "TodoItem.h"
using namespace std;

class TodoManager {
private:
    string filePath;
    vector<TodoItem> todos;
    int nextId;

    void loadFromFile();
    void saveToFile() const;

public:
    TodoManager(const string& filePath);

    void listTodos() const;
    void addTodo(const string& text);
    bool updateTodo(int id, const string& newText);
    bool toggleDone(int id);
    bool deleteTodo(int id);
};

#endif
