#include "Route.h"

using namespace std;

void displayRoute(Route route) {
    cout << "����: " << route.from << " - " << route.to << ".\n  �������: " << route.price << ".\n";
}

void displayAllInfoAboutRoute(Route route) {
    cout << "> ����: " << route.from << " - " << route.to << ".\n    �������: " << route.price << ".\n";
    cout << "    ʳ������ ����: " << route.count << endl;
}
