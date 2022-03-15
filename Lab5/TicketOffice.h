#pragma once

#include <string>

using namespace std;

class TicketOffice {
    int number{};

protected:
    unsigned int ticket{};

public:
    string passenger_name{};

    virtual void sellTicket() = 0;
    virtual void showTicketType() = 0;
    virtual void callTaxi() = 0;

    void setNumber(int number);

    int getNumber();
};