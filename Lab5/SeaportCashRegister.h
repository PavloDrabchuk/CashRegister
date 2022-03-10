#pragma once
#include "CashRegister.h"
class SeaportCashRegister :private CashRegister {
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

/*
class SeaportCashRegister :private CashRegister {
public:

    SeaportCashRegister(){}

    SeaportCashRegister(
        int number,
        long long workingHours[4],
        unsigned int countRouts,
        Route* routs,
        float revenue,
        float maxRevenue,
        int paper) {
        setNumber(number);
        //this->number = number;

        for (int i = 0; i < 4; i++) {
            this->workingHours[i] = workingHours[i];
        }

        this->countRouts = countRouts;
        this->routs = routs;

        this->revenue = revenue;
        this->maxRevenue = maxRevenue;
        this->paper = paper;

        countCashRegisters++;
    }

    void showTicketType() {
        cout << "Квиток на морський транспорт.\n";
    }
    void callTaxi() {

        cout << "Порт: таксі викликано.\n";
    }
*/