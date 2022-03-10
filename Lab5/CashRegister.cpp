#include "CashRegister.h"
#include "WorkingHours.h"
//#include "Lab5.cpp"
//#include "Route.cpp"

/*long long* generateWorkingHours(int hm[8], long long midnight, long long workingHours[]) {
    for (int i = 0; i < 4; i++) {
        workingHours[i] = midnight + (static_cast<long long>(hm[i * 2]) - 2) * 3600 + static_cast<long long>(hm[i * 2 + 1]) * 60;
    }
    return workingHours;
}

time_t getMidnight() {
    time_t now = time(0);
    return now - now % 86400;
}*/

// ����������� �� ������������
CashRegister::CashRegister() {
    countCashRegisters++;
}

// ����������� � �����������
CashRegister::CashRegister(
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

// ����������� ���������
CashRegister::CashRegister(CashRegister& cashRegister) {
    // todo ��� ����� ���� ����������
    //this->number = cashRegister.number;
    //setNumber(cashRegister.)
    this->setNumber(cashRegister.getNumber());

    for (int i = 0; i < 4; i++) {
        this->workingHours[i] = cashRegister.workingHours[i];
    }

    this->countTickets = cashRegister.countTickets;
    this->countRouts = cashRegister.countRouts;
    this->routs = cashRegister.routs;

    this->revenue = cashRegister.revenue;
    this->maxRevenue = cashRegister.maxRevenue;
    this->paper = cashRegister.paper;

    this->countReturnedTickets = cashRegister.countReturnedTickets;
    this->numberReturnedTickets = cashRegister.numberReturnedTickets;

    for (int i = 0; i < cashRegister.countTickets; i++) {
        this->soldTickets[i] = cashRegister.soldTickets[i];
    }

    for (int i = 0; i < cashRegister.numberReturnedTickets; i++) {
        this->returnedTicketsNumbers[i] = cashRegister.returnedTicketsNumbers[i];
    }

    countCashRegisters++;
}

// ����������
CashRegister::~CashRegister() {
    countCashRegisters--;
    // cout << "���������� �����������.\n";
}

/*int getNumber() {
    return number;
}

void setNumber(int n) {
    this->number = n;
}*/

unsigned int CashRegister::getTicket() {
    return ticket;
}

void CashRegister::setTicket(unsigned int t) {
    this->ticket = t;
}

long long* CashRegister::getWorkingHours() {
    return workingHours;
}

void CashRegister::setWorkingHours(long long workingHours[]) {
    for (int i = 0; i < 4; i++) {
        this->workingHours[i] = workingHours[i];
    }
}

unsigned int CashRegister::getCountRouts() {
    return countRouts;
}

void CashRegister::setCountRouts(unsigned int c) {
    this->countRouts = c;
}

Route CashRegister::getRoute(int i) {
    return routs[i];
}

void CashRegister::setRoute(int i, Route route) {
    this->routs[i] = route;
}

Route* CashRegister::getRouts() {
    return routs;
}

void CashRegister::setRouts(Route* routs) {
    this->routs = routs;
}

float CashRegister::getRevenue() {
    return revenue;
}

void CashRegister::setRevenue(float revenue) {
    this->revenue = revenue;
}

float CashRegister::getMaxRevenue() {
    return maxRevenue;
}

void CashRegister::setMaxRevenue(float maxRevenue) {
    this->maxRevenue = maxRevenue;
}

int CashRegister::getPaper() {
    return paper;
}

void CashRegister::setPaper(int paper) {
    this->paper = paper;
}

int CashRegister::getCountTickets() {
    return countTickets;
}

void CashRegister::setCountTickets(int countTickets) {
    this->countTickets = countTickets;
}

Ticket* CashRegister::getSoldTickets() {
    return soldTickets;
}

int* CashRegister::getReturnedTicketsNumbers() {
    return returnedTicketsNumbers;
}

int CashRegister::getCountReturnedTickets() {
    return countReturnedTickets;
}

void CashRegister::setCountReturnedTickets(int countReturnedTickets) {
    this->countReturnedTickets = countReturnedTickets;
}

int CashRegister::getNumberReturnedTickets() {
    return numberReturnedTickets;
}

void CashRegister::setNumberReturnedTickets(int numberReturnedTickets) {
    this->numberReturnedTickets = numberReturnedTickets;
}

 int CashRegister::getCountCashRegisters() {
    return countCashRegisters;
}

bool CashRegister::checkWorking() {
    time_t now = time(0);

    if ((now >= workingHours[0] && now < workingHours[2]) || (now >= workingHours[3] && now <= workingHours[1])) {
        return true;
    }
    else {
        return false;
    }
}

void CashRegister::checkStatus() {
    time_t now = time(0);

    if (now >= workingHours[2] && now <= workingHours[3]) {
        this->passenger_name = "���";
    }
    else if (!checkWorking()) {
        this->passenger_name = "���� �� ������";
    }
    else {
        this->passenger_name = "������� ���";
    }
}

void CashRegister::sellTicket() { // �� ��������?
    cout << (checkWorking() ? "���� ������." : "���� �� ������.") << endl;
}

void CashRegister::sellTicket(string from, string to, int count, string passenger_name) {
    (passenger_name == "") ? this->passenger_name = "��'� ��������" : this->passenger_name = passenger_name;

    if (checkWorking()) {

        int searchRouteResult = searchRoute(from, to, count);

        if (searchRouteResult == -1) {
            cout << "�� ������ ����������� �������� �� ��������.\n";
        }
        else if (searchRouteResult == -2) {
            cout << "����������� ������ ���� �� �������� �������.\n";
        }
        else if (checkPaper(count)) {
            cout << "������� ��������.\n";

            int ticket_num;

            for (int i = 0; i < count; i++) {
                ticket_num = getTicketNum();
                this->ticket = ticket_num;

                soldTickets[countTickets] = Ticket(ticket_num, this->passenger_name, routs[searchRouteResult]);
                countTickets++;
            }

            routs[searchRouteResult].count -= count;
            revenue += (routs[searchRouteResult].price * count);
            paper -= count;

            cout << (count > 1 ? "������" : "������") << " �������.\n";

            checkCollectionRevenue();
            this->passenger_name = "";
        }
    }
    else {
        cout << "���� �� ������.\n";
    }
}

int CashRegister::getTicketNum() {
    if (countReturnedTickets == 0) return countTickets + 1;
    else {
        int result = returnedTicketsNumbers[0];

        for (int i = 0; i < countReturnedTickets; i++) {
            returnedTicketsNumbers[i] = returnedTicketsNumbers[i + 1];
        }

        countReturnedTickets--;
        return result;
    }
}

int CashRegister::searchRoute(string from, string to, int count) {
    for (unsigned int i = 0; i < countRouts; i++) {
        if (routs[i].from == from && routs[i].to == to) {
            return routs[i].count >= count ? i : -2;
            break;
        }
    }
    return -1;
}

bool CashRegister::checkPaper(int count) {
    if (paper - count <= 10 && paper - count > 0) {
        cout << "���������� ���� ������ ��� ����, ����������� �� �����.\n";
    }
    else if (paper - count <= 0) {
        cout << "���� ���������, ������� ����.\n";
        return false;
    }
    return true;
}

void CashRegister::checkCollectionRevenue() {
    if (revenue > maxRevenue) {
        cout << "��������� ���������.\n";
        revenue -= revenue * 0.9f;
    }
}

void CashRegister::returnTicket(int number) {
    if (checkWorking()) {
        revenue -= soldTickets[number - 1].getRoute().price;

        int searchRouteResult = searchRoute(soldTickets[number - 1].getRoute().from, soldTickets[number - 1].getRoute().to, -1);

        routs[searchRouteResult].count++;

        for (int i = number - 1; i < countTickets; i++) {
            soldTickets[i] = soldTickets[i + 1];
        }

        returnedTicketsNumbers[countReturnedTickets] = number;
        countReturnedTickets++;
        numberReturnedTickets++;

        countTickets--;
        cout << "������ ���������.\n";
    }
    else {
        cout << "���� �� ������.\n";
    }
}

void CashRegister::display() {
    cout << *this;
}

void CashRegister::displaySoldTickets() {
    for (int i = 0; i < countTickets; i++) {
        cout << " *** ����� ������: " << soldTickets[i].getNumber() << " ***" << endl;
        cout << "  �������: " << soldTickets[i].getPassengerName() << endl;
        cout << "  ";
        displayRoute(soldTickets[i].getRoute());

        cout << endl;
    }
}

void CashRegister::displayRouts() {
    for (unsigned int i = 0; i < countRouts; i++) {
        displayAllInfoAboutRoute(routs[i]);
    }
}

void CashRegister::init() {
    cin >> *this;
}

void CashRegister::save(string filename) {
    ofstream file(filename);

    file << *this;

    file.close();

    cout << "���������� ��������� � ����: " << filename << ".\n";
}

void CashRegister::read(string filename) {
    ifstream file;
    file.open(filename);

    file >> *this;

    file.close();

    cout << "���������� ��������� � �����: " << filename << ".\n";
}

istream& operator>>(istream& input, CashRegister& cashRegister) {
    unsigned int countRouts;
    int number;

    int hours_and_minutes[8];
    string messages[8] = {
        "������ �������",
        "������� �������",
        "������ ���������",
        "������� ���������",
        "������ �������",
        "������� �������",
        "������ ���������",
        "������� ���������"
    };

    cout << "������ ����� ����: ";
    input >> number;
    cashRegister.setNumber(number);

    cout << "������ ������ ������:\n";

    for (int i = 0; i < 8; i++) {
        cout << "  ������ " << messages[i] << (i < 4 ? " �������� ���" : " �������") << ": ";
        input >> hours_and_minutes[i];

        if (i % 2 == 1) cout << endl;
    }
    generateWorkingHours(hours_and_minutes, getMidnight(), cashRegister.workingHours);

    cout << "������ ������� ��������: ";
    input >> countRouts;

    cashRegister.countRouts = countRouts;
    Route* routs = new Route[countRouts];

    if (countRouts > 0) cout << "������ ���������� ��� ��������:\n";
    for (unsigned int i = 0; i < countRouts; i++) {
        cout << "������� �" << i + 1 << ":\n";
        cout << "  ������ ��������� ���� (�����): ";
        input >> routs[i].from;

        cout << "  ������ ���� ����������� (����): ";
        input >> routs[i].to;

        cout << "  ������ ������� ��������: ";
        input >> routs[i].price;

        cout << "  ������ ������� ����: ";
        input >> routs[i].count;

        cout << endl;
    }
    cashRegister.routs = routs;

    cout << "������ ������� ��������� �������: ";
    input >> cashRegister.revenue;

    cout << "������ �������� ���� ������� ��� ���������: ";
    input >> cashRegister.maxRevenue;

    cout << "������ ������� ������: ";
    input >> cashRegister.paper;

    return input;
}

 ostream& operator<<(ostream& output, CashRegister& cashRegister) {
    tm timeinfo;
    char buffer[80];

    string dateFormats[4] = {
        "������ ������: %H:%M -",
        " %H:%M.\n",
        "�������: %H:%M -",
        " %H:%M.\n" };

    output << "\n ***** ���� �" << cashRegister.getNumber() << " *****" << endl;

    for (int i = 0; i < 4; i++) {
        localtime_s(&timeinfo, &cashRegister.workingHours[i]);
        strftime(buffer, 80, dateFormats[i].c_str(), &timeinfo);
        output << buffer;
    }

    output << "��������:\n";
    for (unsigned int i = 0; i < cashRegister.countRouts; i++) {
        output << "> ����: " << cashRegister.routs[i].from << " - " << cashRegister.routs[i].to << ".\n    �������: " << cashRegister.routs[i].price << ".\n";
        output << "    ʳ������ ����: " << cashRegister.routs[i].count << endl;
    }

    output << "\nʳ������ �������� ������: " << cashRegister.countTickets << endl;

    if (cashRegister.countTickets > 0) {
        output << "������ ������:\n";
        for (int i = 0; i < cashRegister.countTickets; i++) {
            output << " *** ����� ������: " << cashRegister.soldTickets[i].getNumber() << " ***" << endl;
            output << "  �������: " << cashRegister.soldTickets[i].getPassengerName() << endl;
            output << "  ";
            output << "����: " << cashRegister.soldTickets[i].getRoute().from << " - " << cashRegister.soldTickets[i].getRoute().to << ".\n  �������: " << cashRegister.soldTickets[i].getRoute().price << ".\n";

            output << endl;
        }
    }
    else output << "������� ������ �� �������.\n";

    output << endl;

    if (cashRegister.numberReturnedTickets > 0) {
        output << "ʳ������ ���������� ������: " << cashRegister.numberReturnedTickets << endl;
    }
    else output << "������� ������ �� ���������.\n";

    output << endl;

    output << "������� ����������:\n";
    output << "ʳ������ ������: " << cashRegister.paper << " ��.\n";
    output << "�������: " << cashRegister.revenue << " ���.\n";
    output << "�������� ���� ������� ��� ���������: " << cashRegister.maxRevenue << " ���.\n";

    cashRegister.checkStatus();
    output << "\n >> ������ ����: " << cashRegister.passenger_name << ".\n";
    output << "---------------------------------\n";

    return output;
}

 ifstream& operator>>(ifstream& fileInput, CashRegister& cashRegister) {
    // �������������� ��� � �����

    int n, number;
    string p1, p2;

    while (!fileInput.eof()) {
        fileInput >> number;
        cashRegister.setNumber(number);

        for (int i = 0; i < 4; i++) {
            fileInput >> cashRegister.workingHours[i];
        }
        fileInput >> cashRegister.revenue >> cashRegister.maxRevenue >> cashRegister.paper;

        fileInput >> cashRegister.countRouts;
        Route* r = new Route[cashRegister.countRouts];

        for (unsigned int i = 0; i < cashRegister.countRouts; i++) {
            fileInput >> r[i].from >> r[i].to >> r[i].price >> r[i].count;
        }
        cashRegister.routs = r;

        fileInput >> cashRegister.countTickets;

        Route route;

        for (int i = 0; i < cashRegister.countTickets; i++) {
            fileInput >> n;
            cashRegister.soldTickets[i].setNumber(n);

            fileInput >> p1 >> p2;
            cashRegister.soldTickets[i].setPassengerName(p1 + " " + p2);

            fileInput >> route.from >> route.to >> route.price >> route.count;

            cashRegister.soldTickets[i].setRoute(route);
        }

        fileInput >> cashRegister.numberReturnedTickets;

        fileInput >> cashRegister.countReturnedTickets;
        for (int i = 0; i < cashRegister.countReturnedTickets; i++) {
            fileInput >> cashRegister.returnedTicketsNumbers[i];
        }
    }

    return fileInput;
}

 ofstream& operator<<(ofstream& fileOutput, CashRegister& cashRegister) {
    // �������������� ���� � ����

    fileOutput << cashRegister.getNumber() << endl;

    for (int i = 0; i < 4; i++) {
        fileOutput << cashRegister.workingHours[i] << " ";
    }
    fileOutput << endl << cashRegister.revenue << endl << cashRegister.maxRevenue << endl << cashRegister.paper << endl;

    fileOutput << cashRegister.countRouts << endl;
    for (unsigned int i = 0; i < cashRegister.countRouts; i++) {
        fileOutput << cashRegister.routs[i].from << " " << cashRegister.routs[i].to << " " << cashRegister.routs[i].price << " " << cashRegister.routs[i].count << endl;
    }
    fileOutput << endl;

    fileOutput << cashRegister.countTickets << endl;
    for (int i = 0; i < cashRegister.countTickets; i++) {
        fileOutput << cashRegister.soldTickets[i].getNumber() << endl;
        fileOutput << cashRegister.soldTickets[i].getPassengerName() << endl;
        fileOutput << cashRegister.soldTickets[i].getRoute().from << "\n" << cashRegister.soldTickets[i].getRoute().to << "\n" << cashRegister.soldTickets[i].getRoute().price << " " << cashRegister.soldTickets[i].getRoute().count << endl;
    }
    fileOutput << endl;

    fileOutput << cashRegister.numberReturnedTickets << endl;

    fileOutput << cashRegister.countReturnedTickets;
    if (cashRegister.countReturnedTickets > 0)cout << endl;

    for (int i = 0; i < cashRegister.countReturnedTickets; i++) {
        fileOutput << cashRegister.returnedTicketsNumbers[i] << " ";
    }

    return fileOutput;
}

 bool operator>(const CashRegister& cashRegister1, const CashRegister& cashRegister2) {
    return cashRegister1.countTickets > cashRegister2.countTickets;
}

 bool operator<(const CashRegister& cashRegister1, const CashRegister& cashRegister2) {
    return cashRegister1.countTickets < cashRegister2.countTickets;
}

 bool operator==(const CashRegister& cashRegister1, const CashRegister& cashRegister2) {
    return cashRegister1.countTickets == cashRegister2.countTickets;
}

 bool operator!=(const CashRegister& cashRegister1, const CashRegister& cashRegister2) {
    return cashRegister1.countTickets != cashRegister2.countTickets;
}

 bool operator<=(const CashRegister& cashRegister1, const CashRegister& cashRegister2) {
    return cashRegister1.countTickets <= cashRegister2.countTickets;
}

 bool operator>=(const CashRegister& cashRegister1, const CashRegister& cashRegister2) {
    return cashRegister1.countTickets >= cashRegister2.countTickets;
}



//virtual int getArea() = 0;
////// virtual void showTicketType() = 0;
//virtual void sellTicket() = 0;

void CashRegister::callTaxi() {
    cout << "���� ���������.\n";
}

void CashRegister::showTicketType() {
    cout << "������������ ������.\n";
}


// ����� ��������� ����
// г�����: 
//   - ��� �����: ������ ����
//   - ��� �����: ����� ������� �������
//   - ��� �������: ����� ������� ���(?)

string *CashRegister::getCallTaxiInfo() {
    string taxiInfo[4];
    cin.ignore();
    // string taxiRouteTo, phoneNumber, choice = "", comment = "";
    cout << "���� ������� �����������?\n >> ";
    getline(cin, taxiInfo[0]);
    //cin >> taxiRouteTo;

    cout << "������ ��� �������� �����: ";
    getline(cin, taxiInfo[1]);

    //cout << "h: " << taxiRouteTo << "\n";

    while (taxiInfo[2] != "1" && taxiInfo[2] != "2") {
        cout << "������� ����� ������ (������ (1) �� �������� ������ (2)): ";
        getline(cin, taxiInfo[2]);
    }

    cout << "������ �������� ��� ����: ";
    getline(cin, taxiInfo[3]);

    return taxiInfo;
}

void CashRegister::displayTaxiTicketInfo(string* taxiCallInfo) {
    cout << "  ������ �����������: " << taxiCallInfo[0] << ".\n";
    cout << "  �������� �����: " << taxiCallInfo[1] << ".\n";
    cout << "  ����� ������: " << (taxiCallInfo[2] == "1" ? "������" : "�������� ������") << ".\n";
    cout << "  ��������" << (taxiCallInfo[3] == "" ? " �������" : ": " + taxiCallInfo[3]) << ".\n";
}
