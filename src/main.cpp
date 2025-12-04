// src/main.cpp
#include "App.h"
#include <filesystem>
#include <iostream>

int main() {
    // ensure data directory exists (C++17)
    std::filesystem::create_directory("data");

    App app("data/users.txt");
    app.run();

    return 0;
}
