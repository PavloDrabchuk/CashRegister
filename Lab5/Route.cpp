#include "Route.h"

using namespace std;

void displayRoute(Route route) {
    cout << "Рейс: " << route.from << " - " << route.to << ".\n  Вартість: " << route.price << ".\n";
}

void displayAllInfoAboutRoute(Route route) {
    cout << "> Рейс: " << route.from << " - " << route.to << ".\n    Вартість: " << route.price << ".\n";
    cout << "    Кількість місць: " << route.count << endl;
}
