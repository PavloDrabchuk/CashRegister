#pragma once

#include <iostream>
//#include <string>

using namespace std;

struct Route {
    string from{};
    string to{};
    float price{};
    short count{};

    //void displayRoute(Route route);

    //void displayAllInfoAboutRoute(Route route);
};

void displayRoute(Route route);

void displayAllInfoAboutRoute(Route route);

/*
struct Route {
    string from{};
    string to{};
    float price{};
    short count{};
};

void displayRoute(Route route) {
    cout << "����: " << route.from << " - " << route.to << ".\n  �������: " << route.price << ".\n";
}

void displayAllInfoAboutRoute(Route route) {
    cout << "> ����: " << route.from << " - " << route.to << ".\n    �������: " << route.price << ".\n";
    cout << "    ʳ������ ����: " << route.count << endl;
}
*/

