#include "WorkingHours.h"


//#include "Route.h"

long long* generateWorkingHours(int hm[8], long long midnight, long long workingHours[]) {
    for (int i = 0; i < 4; i++) {
        workingHours[i] = midnight + (static_cast<long long>(hm[i * 2]) - 2) * 3600 + static_cast<long long>(hm[i * 2 + 1]) * 60;
    }
    return workingHours;
}

time_t getMidnight() {
    time_t now = time(0);
    return now - now % 86400;
}

/*void displayRoute(Route route) {
    cout << "Рейс: " << route.from << " - " << route.to << ".\n  Вартість: " << route.price << ".\n";
}

void displayAllInfoAboutRoute(Route route) {
    cout << "> Рейс: " << route.from << " - " << route.to << ".\n    Вартість: " << route.price << ".\n";
    cout << "    Кількість місць: " << route.count << endl;
}*/