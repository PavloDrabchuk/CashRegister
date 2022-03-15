#pragma once
#include "CashRegister.h"
class AirportCashRegister :protected CashRegister {
public:

    AirportCashRegister();

    AirportCashRegister(
        int number,
        long long workingHours[4],
        unsigned int countRouts,
        Route* routs,
        float revenue,
        float maxRevenue,
        int paper);

    void showTicketType();

    void callTaxi();
};

