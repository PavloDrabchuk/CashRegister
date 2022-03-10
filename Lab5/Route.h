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
    cout << "Ðåéñ: " << route.from << " - " << route.to << ".\n  Âàðò³ñòü: " << route.price << ".\n";
}

void displayAllInfoAboutRoute(Route route) {
    cout << "> Ðåéñ: " << route.from << " - " << route.to << ".\n    Âàðò³ñòü: " << route.price << ".\n";
    cout << "    Ê³ëüê³ñòü ì³ñöü: " << route.count << endl;
}
*/

