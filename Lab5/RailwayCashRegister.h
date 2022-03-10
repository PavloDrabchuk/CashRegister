#pragma once
#include "CashRegister.h"

class RailwayCashRegister :public CashRegister {
public:

    RailwayCashRegister();

    RailwayCashRegister(
        int number,
        long long workingHours[4],
        unsigned int countRouts,
        Route* routs,
        float revenue,
        float maxRevenue,
        int paper);

    void showTicketType();

    void showTicketNumber();

    void callTaxi();
};

