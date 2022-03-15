#include "SeaportCashRegister.h"

SeaportCashRegister::SeaportCashRegister() {}

SeaportCashRegister::SeaportCashRegister(
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

void SeaportCashRegister::showTicketType() {
    cout << "������ �� �������� ���������.\n";
}

void SeaportCashRegister::callTaxi() {
    cout << "\n >> ������ ���� [�������� ������] <<\n";

    string taxiInfo[4];
    getCallTaxiInfo(taxiInfo);

    cout << "\n�������� ������:\n >> ���� ���������:\n";
    displayTaxiTicketInfo(taxiInfo);
}
