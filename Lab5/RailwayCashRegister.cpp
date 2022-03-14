#include "RailwayCashRegister.h"

RailwayCashRegister::RailwayCashRegister() {
    cout << "Default Railway constructor.\n";
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

void RailwayCashRegister::showTicketType() {
    cout << "���������� ������.\n";
}

void RailwayCashRegister::showTicketNumber() {
    cout << "Ticket: " << ticket << endl;
}

void RailwayCashRegister::callTaxi() {
    //cout << "���������� ������: ���� ���������.\n";
    string taxiInfo[4];
    //string *taxiInfo = getCallTaxiInfo();
    getCallTaxiInfo(taxiInfo);
    //cout << "---> " << taxiInfo[0] << endl;

    //string terminal;

    //cout << "�� ����� �������� ������ ����?\n >> ";
    //getline(cin, terminal);

    cout << "���������� ������:\n >> ���� ���������:\n";
    displayTaxiTicketInfo(taxiInfo);
}
