#include "AirportCashRegister.h"

AirportCashRegister::AirportCashRegister() {}

AirportCashRegister::AirportCashRegister(
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

void AirportCashRegister::showTicketType() {
    cout << "������ �� ����.\n";
}

void AirportCashRegister::callTaxi() {
    cout << "\n >> ������ ���� [��������] <<\n";

    string taxiInfo[4], terminal;
    getCallTaxiInfo(taxiInfo);

    cout << "�� ����� �������� ������ ����?\n >> ";
    getline(cin, terminal);

    cout << "\n��������:\n >> ���� ���������:\n  �������: " << terminal << ".\n";
    displayTaxiTicketInfo(taxiInfo);
}
