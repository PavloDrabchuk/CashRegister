#include "Ticket.h"

Ticket::Ticket(int n, string p, Route route) {
    this->number = n;
    this->passenger_name = p;
    this->route = route;
}

Ticket::Ticket(int n, string p) {
    this->number = n;
    this->passenger_name = p;
}

int Ticket::getNumber() {
    return number;
}

void Ticket::setNumber(int n) {
    this->number = n;
}

string Ticket::getPassengerName() {
    return passenger_name;
}

void Ticket::setPassengerName(string p) {
    this->passenger_name = p;
}

Route Ticket::getRoute() {
    return route;
}

void Ticket::setRoute(Route route) {
    this->route = route;
}
