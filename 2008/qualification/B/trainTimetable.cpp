/*
 * trainTimetable.cpp
 * Copyright (C) 2018 Quentin Kniep <hello@quentinkniep.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <set>
#include <string>


struct route {
	int start, end;
	int station;

	bool operator<(const route& b) const {
		return start < b.start;
	}
};


// Reads a single set of timetbale inputs (i.e. for one station).
void readTimes(std::multiset<route>& vec, int n, int turnTime, int station) {
	for (int i = 0; i < n; ++i) {
		int startH, startM, endH, endM;
		scanf("%d:%d %d:%d\n", &startH, &startM, &endH, &endM);
		int startTime = startH*60 + startM;
		int endTime = endH*60 + endM + turnTime;
		vec.insert(route{startTime, endTime, station});
	}
}

int main() {
	std::string line;
	std::getline(std::cin, line);
	int n = std::stoi(line);

	for (int i = 0; i < n; ++i) {
		std::getline(std::cin, line);
		int turnTime = std::stoi(line);

		// read timetable input
		int na, nb = 0;
		scanf("%d %d\n", &na, &nb);
		std::multiset<route> routes;
		readTimes(routes, na, turnTime, 0);
		readTimes(routes, nb, turnTime, 1);

		int trainsStarted[2] = {0, 0};
		std::multiset<int> currentTrains[2];

		for (auto const& currentRoute : routes) {
			auto availableTrain = currentTrains[currentRoute.station].begin();
			if (currentTrains[currentRoute.station].empty() || (*availableTrain) > currentRoute.start) {
				trainsStarted[currentRoute.station]++;  // new train
			} else {
				currentTrains[currentRoute.station].erase(availableTrain);  // train switches stations
			}
			currentTrains[1-currentRoute.station].insert(currentRoute.end);
		}


		std::cout << "Case #" << (i+1) << ": " << trainsStarted[0] << " " << trainsStarted[1] << std::endl;
	}
}
