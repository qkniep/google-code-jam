/*
 * searchEngines.cpp
 * Copyright (C) 2018 Quentin Kniep <hello@quentinkniep.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <string>
#include <unordered_map>


int main() {
	std::string line;
	std::getline(std::cin, line);
	int numTestCases = std::stoi(line);

	for (int i = 0; i < numTestCases; ++i) {
		int switchesNecessary = 0;
		std::unordered_map<std::string, bool> searchEngines;

		std::getline(std::cin, line);
		int numSearchEngines = std::stoi(line);

		for (int s = 0; s < numSearchEngines; ++s) {
			std::getline(std::cin, line);
			searchEngines[line] = true;
		}

		std::getline(std::cin, line);
		int numQueries = std::stoi(line);

		std::unordered_map<std::string, bool> possibleSearchEngines;
		possibleSearchEngines.insert(searchEngines.begin(), searchEngines.end());
		int numPossibleSearchEngines = numSearchEngines;

		for (int q = 0; q < numQueries; ++q) {
			std::getline(std::cin, line);
			if (possibleSearchEngines[line]) {
				if (numPossibleSearchEngines == 1) {
					switchesNecessary++;
					numPossibleSearchEngines = numSearchEngines;
					possibleSearchEngines.clear();
					possibleSearchEngines.insert(searchEngines.begin(), searchEngines.end());
				}
				possibleSearchEngines[line] = false;
				numPossibleSearchEngines--;
			}
		}

		std::cout << "Case #" << (i+1) << ": " << switchesNecessary << std::endl;
	}


	return 0;
}
