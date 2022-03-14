// Lab5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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
    //c->showTicketType();
   
    /*cin.ignore();
    string taxiRouteTo, comment = "", phoneNumber, choice = "";
    cout << "Куди потрібно відправитись?\n >> ";
    getline(cin, taxiRouteTo);
    //cin >> taxiRouteTo;

    cout << "Введіть Ваш мобільний номер: ";
    getline(cin, phoneNumber);

    //cout << "h: " << taxiRouteTo << "\n";

    while (choice != "1" && choice != "2") {
        cout << "Виберіть спосіб оплати (готівка (1) чи кредитна картка (2)): ";
        getline(cin, choice);
    }

    cout << "Введіть коментар для водія: ";
    getline(cin, comment);
    */

    t->callTaxi();
    //c->callTaxi();
}

void showTicketTypePoly(TicketOffice* t) {
    t->showTicketType();
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //char buffer[80];

    //time_t midnight = getMidnight();

    //time_t now = time(0);
    //tm timeinfo;

    //localtime_s(&timeinfo, &now);
    //strftime(buffer, 80, " *** Зараз: %d.%m.%G %H:%M:%S ***\n", &timeinfo);
    //cout << buffer;

    int hours_and_minutes[] = { 9,0,17,50,13,00,14,0 };
    // int hours_and_minutes[] = { 17,0,23,50,18,30,19,50 };

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

    //CashRegister cashRegister;
    //cashRegister.sellTicket();
    //cashRegister.callTaxi();
    
    //cout << endl << "1.3.2:\n";
        
    //RailwayCashRegister r(2, workingHours, count_of_routs, routs, 0, 1000, 50);
    RailwayCashRegister r;
    cout << "\nВведення інформації з клавіатури для екземпляру класу-нащадка:\n";
    r.init();
    
    //r.showTicketType();
    
    //r.callTaxi();
    
    cout << "\n1.3.2:\n";

    cout << "\nRailwayCashRegister:\n";
    //cout << " [public] - Ім'я пасажира: " << r.passenger_name << endl;
    //cout << " [protected] - Номер квитка: " << r.getTicket() << endl;
    
    cout << " [TicketOffice.number] - Номер каси: " << r.getNumber() << endl;
    r.passenger_name = "Сергій Роженко"; // ім'я задається так, бо після продажу квитка має бути очищеним
    cout << " [TicketOffice.passenger_name] - Ім'я пасажира: " << r.passenger_name << endl;
    
    cout << " [CashRegister.revenue] - Сума виручки: " << r.getRevenue() << endl;
    cout << " [CashRegister.paper] - Кількість паперу: " << r.getPaper() << endl;
    cout << " [CashRegister.countTickets] - Кількість проданих квитків: " << r.getCountTickets() << endl;

    cout << endl;

    // todo: Таке саме для Аеропорту та Морського порту

    // ========= 1.3.3 =========
    //cout << "RailwayCashRegister.ticket - Номер каси: " << r.ticket << endl;
    //cout << "CashRegister.ticket - Номер каси: " << cashRegister1.ticket << endl;

    cout << "1.3.4:\n";
    cout << "CashRegister.passenger_name: " << cashRegister1.passenger_name << endl;
    cout << "RailwayCashRegister.passenger_name: " << r.passenger_name << endl;
    
    cout << "\n2.1 \"Поліморфна функція\":\n";
    callTaxiPoly(&r);

    AirportCashRegister a;
    //a.setTerminal("2B");
    //SeaportCashRegister s;
    
    //callTaxiPoly(&a);
    a.callTaxi();

    //callTaxiPoly(&r);

    SeaportCashRegister s;
    s.callTaxi();
    //poly(&s);

    cout << "\nВикористання поліморфної функції для перевірки типу квитка:\n";
    showTicketTypePoly(&r);
    //showTicketTypePoly(&a);
    a.showTicketType();
    s.showTicketType();



    /*
    AirportCashRegister a;
    a.callTaxi();
    a.setTerminal("D");
    cout << "[private] - AirportCashRegister.terminal: " << a.getTerminal() << endl;


    cout << endl;

    
    SeaportCashRegister s;
    s.callTaxi();

    cout << "SeaportCashRegister (error):\n";
    // cout << " [public] - Ім'я пасажира: " << s.passenger_name << endl;
    // cout << " [protected] - Номер квитка: " << s.getTicket() << endl;
    // cout << " [private] - Номер каси: " << s.getNumber() << endl;

    cout << "Порівняння:\n";
    cout << "Звертання до поля у безпосередньому нащадку: " << cashRegister1.passenger_name << endl;
    cout << "Звертання до поля у нащадку через покоління: " << r.passenger_name << endl;
    cout << endl;


    poly(&r);
    */

    // poly(&a);
     //poly(&s);

    //cout << "Passanger name: " << r.passenger_name << endl;
    //cout << "Ticket: " << r.ticket << endl;

    //cout << "Hello World!\n";

    system("pause");
    return 0;
}
