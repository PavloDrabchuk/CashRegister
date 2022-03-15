#include <iostream>
#include "windows.h"
#include <fstream>
#include <string>
#include <ctime>
#include <time.h>

#include "CashRegister.h"

#include "RailwayCashRegister.h"
#include "AirportCashRegister.h"
#include "SeaportCashRegister.h"
#include "WorkingHours.h"

using namespace std;

unsigned int CashRegister::countCashRegisters = 0;

void callTaxiPoly(TicketOffice* t) {
    t->callTaxi();
}

void showTicketTypePoly(TicketOffice* t) {
    t->showTicketType();
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int hours_and_minutes[8] = { 9,0,17,50,13,00,14,0 };

    long long workingHours[4];
    generateWorkingHours(hours_and_minutes, getMidnight(), workingHours);

    const unsigned int count_of_routs = 4;
    Route* routs = new Route[count_of_routs]{
        {"Івано-Франківськ", "Львів", 22, 12},
        {"Івано-Франківськ", "Чернівці", 20, 10},
        {"Івано-Франківськ", "Тернопіль", 19, 3},
        {"Івано-Франківськ", "Рівне", 23, 7}
    };

    CashRegister cashRegister1(1, workingHours, count_of_routs, routs, 0, 1000, 50);
    
    cashRegister1.setTicket(2);
    cashRegister1.passenger_name = "Андрій Васильченко";

    cout << "1.3.1:\n";

    cout << "[public] - Ім'я пасажира: " << cashRegister1.passenger_name << endl;
    cout << "[protected] - Номер квитка: " << cashRegister1.getTicket()<< endl;
    cout << "[private] - Номер каси: " << cashRegister1.getNumber() << endl;
    
    RailwayCashRegister r;
    AirportCashRegister a;
    SeaportCashRegister s;
    
    cout << "\nВведення інформації з клавіатури для екземпляру класу-нащадка:\n";
    r.init();
    
    cout << "\n1.3.2:\n";
    cout << "\nRailwayCashRegister:\n";

    cout << " [TicketOffice.number] - Номер каси: " << r.getNumber() << endl;
    r.passenger_name = "Сергій Роженко"; // ім'я задається так, бо після продажу квитка має бути очищеним
    cout << " [TicketOffice.passenger_name] - Ім'я пасажира: " << r.passenger_name << endl;
    
    cout << " [CashRegister.revenue] - Сума виручки: " << r.getRevenue() << endl;
    cout << " [CashRegister.paper] - Кількість паперу: " << r.getPaper() << endl;
    cout << " [CashRegister.countTickets] - Кількість проданих квитків: " << r.getCountTickets() << endl;

    cout << endl;
    
    // ========= 1.3.3 =========
    //cout << "RailwayCashRegister.ticket - Номер каси: " << r.ticket << endl;
    //cout << "CashRegister.ticket - Номер каси: " << cashRegister1.ticket << endl;
    //cout << "SeaportCashRegister.passenger_name - Ім'я пасажира: " << s.passenger_name << endl;
    
    cout << "1.3.4:\n";
    cout << "CashRegister.passenger_name: " << cashRegister1.passenger_name << endl;
    cout << "RailwayCashRegister.passenger_name: " << r.passenger_name << endl;
    
    cout << "\n2. \"Поліморфна функція\":\n";
    callTaxiPoly(&r);
  
    a.callTaxi();
    s.callTaxi();

    cout << "\nВикористання поліморфної функції для перевірки типу квитка:\n";
    showTicketTypePoly(&r);

    a.showTicketType();
    s.showTicketType();

    system("pause");
    return 0;
}
