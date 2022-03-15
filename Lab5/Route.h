#pragma once

#include <iostream>

using namespace std;

struct Route {
    string from{};
    string to{};
    float price{};
    short count{};
};

void displayRoute(Route route);

void displayAllInfoAboutRoute(Route route);

