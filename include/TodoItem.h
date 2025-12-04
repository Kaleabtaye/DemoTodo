// include/TodoItem.h
#ifndef TODO_ITEM_H
#define TODO_ITEM_H

#include <string>
using namespace std;

class TodoItem {
private:
    int id;
    string text;
    bool done;

public:
    TodoItem() = default;
    TodoItem(int id, const string& text, bool done = false);

    int getId() const;
    string getText() const;
    bool isDone() const;

    void setText(const string& newText);
    void setDone(bool value);
};

#endif
