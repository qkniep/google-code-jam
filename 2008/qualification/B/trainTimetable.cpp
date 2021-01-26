/*
 * Copyright (C) 2018 Quentin M. Kniep <hello@quentinkniep.com>
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <set>
#include <string>

using namespace std;

struct route {
    int start, end;
    int station;

    bool operator<(const route& b) const {
        return start < b.start;
    }
};

// Reads a single set of timetable inputs (i.e. for one station).
void readTimes(multiset<route>& vec, int n, int turnTime, int station) {
    for (int i = 0; i < n; ++i) {
        int startH, startM, endH, endM;
        scanf("%d:%d %d:%d\n", &startH, &startM, &endH, &endM);
        int startTime = startH*60 + startM;
        int endTime = endH*60 + endM + turnTime;
        vec.insert(route{startTime, endTime, station});
    }
}

int main() {
    string line;
    unsigned int T;

    getline(cin, line);
    T = stoi(line);

    for (int t = 1; t <= T; t++) {
        getline(cin, line);
        int turnTime = stoi(line);

        // read timetable input
        int na, nb = 0;
        scanf("%d %d\n", &na, &nb);
        multiset<route> routes;
        readTimes(routes, na, turnTime, 0);
        readTimes(routes, nb, turnTime, 1);

        int trainsStarted[2] = {0, 0};
        multiset<int> currentTrains[2];

        for (auto const& currentRoute : routes) {
            auto availableTrain = currentTrains[currentRoute.station].begin();
            if (currentTrains[currentRoute.station].empty() || (*availableTrain) > currentRoute.start) {
                trainsStarted[currentRoute.station]++;  // new train
            } else {
                currentTrains[currentRoute.station].erase(availableTrain);  // train switches stations
            }
            currentTrains[1-currentRoute.station].insert(currentRoute.end);
        }

        cout << "Case #" << t << ": " << trainsStarted[0] << " " << trainsStarted[1] << endl;
    }
}
