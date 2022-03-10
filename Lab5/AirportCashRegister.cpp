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
    cout << "������ �� ����.\n";
}

void AirportCashRegister::callTaxi(string taxiRouteTo, string comment, string phoneNumber, string choice) {
    /*cin.ignore();
    string taxiRouteTo, comment="", phoneNumber, choice="";
    cout << "���� ������� �����������?\n >> ";
    getline(cin, taxiRouteTo);
    //cin >> taxiRouteTo;

    cout << "������ ��� �������� �����: ";
    getline(cin, phoneNumber);

    //cout << "h: " << taxiRouteTo << "\n";

    while (choice != "1" && choice !="2") {
        cout << "������� ����� ������ (������ (1) �� �������� ������ (2)): ";
        getline(cin, choice);
    }

    cout << "������ �������� ��� ����: ";
    getline(cin, comment);*/

    string *taxiInfo = getCallTaxiInfo();

    string terminal;

    cout << "�� ����� �������� ������ ����?\n >> ";
    getline(cin, terminal);

    cout << "��������:\n >> ���� ���������:\n  �������: " << terminal << ".\n";
    displayTaxiTicketInfo(taxiInfo);
    /*cout << "  ������ �����������: " << taxiRouteTo << ".\n";
    cout << "  �������� �����: " << phoneNumber << ".\n";
    cout << "  ����� ������: " << (choice == "1" ? "������" : "�������� ������") << ".\n";
    cout << "  ��������" << (comment == "" ? " ��������" : ": " + comment) << ".\n";
    */
}

/*string getTerminal() {
    return terminal;
}

void setTerminal(string terminal) {
    this->terminal = terminal;
}*/
