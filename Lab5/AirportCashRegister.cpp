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

void AirportCashRegister::showTicketType() {
    cout << "Квиток на літак.\n";
}

void AirportCashRegister::callTaxi() {
    cout << "\n >> Виклик таксі [Аеропорт] <<\n";

    /*cin.ignore();
    string taxiRouteTo, comment="", phoneNumber, choice="";
    cout << "Куди потрібно відправитись?\n >> ";
    getline(cin, taxiRouteTo);
    //cin >> taxiRouteTo;

    cout << "Введіть Ваш мобільний номер: ";
    getline(cin, phoneNumber);

    //cout << "h: " << taxiRouteTo << "\n";

    while (choice != "1" && choice !="2") {
        cout << "Виберіть спосіб оплати (готівка (1) чи кредитна картка (2)): ";
        getline(cin, choice);
    }

    cout << "Введіть коментар для водія: ";
    getline(cin, comment);*/
    string taxiInfo[4], terminal;
    //string *taxiInfo = getCallTaxiInfo();
    getCallTaxiInfo(taxiInfo);
    //cout << "---> " << taxiInfo[0] << endl;

    cout << "До якого терміналу подати авто?\n >> ";
    getline(cin, terminal);

    cout << "\nАеропорт:\n >> Таксі викликано:\n  Термінал: " << terminal << ".\n";
    displayTaxiTicketInfo(taxiInfo);
    /*cout << "  Адреса відправлення: " << taxiRouteTo << ".\n";
    cout << "  Мобільний номер: " << phoneNumber << ".\n";
    cout << "  Спосіб оплати: " << (choice == "1" ? "готівка" : "кредитна картка") << ".\n";
    cout << "  Коментар" << (comment == "" ? " відсутній" : ": " + comment) << ".\n";
    */
}

/*string getTerminal() {
    return terminal;
}

void setTerminal(string terminal) {
    this->terminal = terminal;
}*/
