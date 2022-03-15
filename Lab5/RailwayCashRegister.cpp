#include "RailwayCashRegister.h"

RailwayCashRegister::RailwayCashRegister() {
    //cout << "Default Railway constructor.\n";
}

RailwayCashRegister::RailwayCashRegister(
    int number,
    long long workingHours[4],
    unsigned int countRouts,
    Route* routs,
    float revenue,
    float maxRevenue,
    int paper) {

    setNumber(number);

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

void RailwayCashRegister::showTicketType() {
    cout << "Залізничний квиток.\n";
}

void RailwayCashRegister::showTicketNumber() {
    cout << "Ticket: " << ticket << endl;
}

void RailwayCashRegister::callTaxi() {
    cout << "\n >> Виклик таксі [Залізничний вокзал] <<\n";

    string taxiInfo[4];
    getCallTaxiInfo(taxiInfo);

    cout << "\nЗалізничний вокзал:\n >> Таксі викликано:\n";
    displayTaxiTicketInfo(taxiInfo);
}
