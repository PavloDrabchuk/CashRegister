#pragma once

#include <string>
#include "Route.h"

using namespace std;

class Ticket {
    int number{};
    string passenger_name{};
    Route route{};

public:
    Ticket() = default;

    Ticket(int n, string p, Route route);

    Ticket(int n, string p);

    int getNumber();

    void setNumber(int n);

    string getPassengerName();

    void setPassengerName(string p);

    Route getRoute();

    void setRoute(Route route);
};

/*
class Ticket {
    int number{};
    string passenger_name{};
    Route route{};

public:
    Ticket() = default;

    Ticket(int n, string p, Route route) {
        this->number = n;
        this->passenger_name = p;
        this->route = route;
    }

    Ticket(int n, string p) {
        this->number = n;
        this->passenger_name = p;
    }

    int getNumber() {
        return number;
    }

    void setNumber(int n) {
        this->number = n;
    }

    string getPassengerName() {
        return passenger_name;
    }

    void setPassengerName(string p) {
        this->passenger_name = p;
    }

    Route getRoute() {
        return route;
    }

    void setRoute(Route route) {
        this->route = route;
    }

};
*/

