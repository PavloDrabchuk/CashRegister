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