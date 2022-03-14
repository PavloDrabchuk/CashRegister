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

void SeaportCashRegister::showTicketType() {
    cout << "Квиток на морський транспорт.\n";
}
void SeaportCashRegister::callTaxi() {
    cout << "\n >> Виклик таксі [Морський вокзал] <<\n";

    //cout << "Залізничний вокзал: таксі викликано.\n";
    string taxiInfo[4];
    //string *taxiInfo = getCallTaxiInfo();
    getCallTaxiInfo(taxiInfo);
    //cout << "---> " << taxiInfo[0] << endl;

    //string terminal;

    //cout << "До якого терміналу подати авто?\n >> ";
    //getline(cin, terminal);

    cout << "\nМорський вокзал:\n >> Таксі викликано:\n";
    displayTaxiTicketInfo(taxiInfo);
    //cout << "Порт: таксі викликано.\n";
}
