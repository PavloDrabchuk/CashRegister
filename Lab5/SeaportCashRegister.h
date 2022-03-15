#pragma once
#include "CashRegister.h"

class SeaportCashRegister :private CashRegister {
public:
    SeaportCashRegister();

    SeaportCashRegister(
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