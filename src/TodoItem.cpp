// src/TodoItem.cpp
#include "TodoItem.h"

TodoItem::TodoItem(int id, const string& text, bool done)
    : id(id), text(text), done(done) {}

int TodoItem::getId() const { return id; }
string TodoItem::getText() const { return text; }
bool TodoItem::isDone() const { return done; }

void TodoItem::setText(const string& newText) { text = newText; }
void TodoItem::setDone(bool value) { done = value; }
