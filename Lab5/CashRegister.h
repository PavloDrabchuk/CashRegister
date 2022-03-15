#pragma once

#include <fstream>
#include <time.h>

#include "TicketOffice.h"
#include "Route.h"
#include "Ticket.h"

class CashRegister :public TicketOffice {
protected:
    static unsigned int countCashRegisters;

    long long workingHours[4]{};

    unsigned int countRouts{};
    Route* routs{};

    float revenue{};
    float maxRevenue{};
    int paper{};

    int countTickets = 0;
    Ticket soldTickets[20]{};

    int returnedTicketsNumbers[20]{};
    int countReturnedTickets = 0;
    int numberReturnedTickets = 0;

public:
    // конструктор по замовчуванню
    CashRegister();

    // конструктор з параметрами
    CashRegister(
        int number,
        long long workingHours[4],
        unsigned int countRouts,
        Route* routs,
        float revenue,
        float maxRevenue,
        int paper);

    // конструктор копіювання
    CashRegister(CashRegister& cashRegister);

    // деструктор
    ~CashRegister();

    unsigned int getTicket();

    void setTicket(unsigned int t);

    long long* getWorkingHours();

    void setWorkingHours(long long workingHours[]);

    unsigned int getCountRouts();

    void setCountRouts(unsigned int c);

    Route getRoute(int i);

    void setRoute(int i, Route route);

    Route* getRouts();

    void setRouts(Route* routs);

    float getRevenue();

    void setRevenue(float revenue);

    float getMaxRevenue();

    void setMaxRevenue(float maxRevenue);

    int getPaper();

    void setPaper(int paper);

    int getCountTickets();

    void setCountTickets(int countTickets);

    Ticket* getSoldTickets();

    int* getReturnedTicketsNumbers();

    int getCountReturnedTickets();

    void setCountReturnedTickets(int countReturnedTickets);

    int getNumberReturnedTickets();

    void setNumberReturnedTickets(int numberReturnedTickets);

    static int getCountCashRegisters();

    bool checkWorking();

    void checkStatus();

    void sellTicket();

    void sellTicket(string from, string to, int count, string passenger_name);

    int getTicketNum();

    int searchRoute(string from, string to, int count);

    bool checkPaper(int count);

    void checkCollectionRevenue();

    void returnTicket(int number);

    void display();

    void displaySoldTickets();

    void displayRouts();

    void init();

    void save(string filename);

    void read(string filename);

    friend istream& operator>>(istream& input, CashRegister& cashRegister);

    friend ostream& operator<<(ostream& output, CashRegister& cashRegister);

    friend ifstream& operator>>(ifstream& fileInput, CashRegister& cashRegister);

    friend ofstream& operator<<(ofstream& fileOutput, CashRegister& cashRegister);

    friend bool operator>(const CashRegister& cashRegister1, const CashRegister& cashRegister2);

    friend bool operator<(const CashRegister& cashRegister1, const CashRegister& cashRegister2);

    friend bool operator==(const CashRegister& cashRegister1, const CashRegister& cashRegister2);

    friend bool operator!=(const CashRegister& cashRegister1, const CashRegister& cashRegister2);

    friend bool operator<=(const CashRegister& cashRegister1, const CashRegister& cashRegister2);

    friend bool operator>=(const CashRegister& cashRegister1, const CashRegister& cashRegister2);

    void callTaxi();

    void showTicketType();

    string* getCallTaxiInfo(string taxiInfo[]);

    void displayTaxiTicketInfo(string* taxiCallInfo);
};

