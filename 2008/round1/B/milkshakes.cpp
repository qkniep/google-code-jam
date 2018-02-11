/*
 * milkshakes.cpp
 * Copyright (C) 2018 Quentin Kniep <hello@quentinkniep.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <queue>
#include <vector>


struct preference {
	int maltedFlavor;
	int nonMaltedCount;
};


int main() {
	int t;
	std::cin >> t;

	for (int i = 0; i < t; ++i) {
		int numFlavors;
		std::cin >> numFlavors;
		int numCustomers;
		std::cin >> numCustomers;

		std::vector<preference> customerPreferences(numCustomers);
		std::vector< std::vector<int> > whoLikesFlavorNM(numFlavors);
		std::queue<int> openList;

		for (int c = 0; c < numCustomers; ++c) {
			int numLikedFlavors;
			std::cin >> numLikedFlavors;

			for (int f = 0; f < numLikedFlavors; ++f) {
				int flavor;
				bool malted;
				std::cin >> flavor >> malted;

				if (numLikedFlavors == 1 && malted) {
					openList.push(c);
				}

				if (malted) {
					customerPreferences[c].maltedFlavor = flavor;
				} else {
					customerPreferences[c].nonMaltedCount += 1;
					whoLikesFlavorNM[flavor-1].push_back(c);
				}
			}
		}

		std::vector<bool> maltedFlavors(numFlavors, false);
		bool success = true;

		while (!openList.empty()) {
			int currentCustomer = openList.front();
			openList.pop();
			int flavor = customerPreferences[currentCustomer].maltedFlavor - 1;

			if (!maltedFlavors[flavor]) {
				maltedFlavors[flavor] = true;

				for (auto const& c : whoLikesFlavorNM[flavor]) {
					customerPreferences[c].nonMaltedCount -= 1;

					if (customerPreferences[c].nonMaltedCount == 0) {
						if (customerPreferences[c].maltedFlavor == 0) {
							success = false;
							break;
						} else {
							openList.push(c);
						}
					}
				}
			}
		}

		if (success) {
			std::cout << "Case #" << (i+1) << ": ";
			std::copy(begin(maltedFlavors), end(maltedFlavors), std::ostream_iterator<int>(std::cout, " "));
			std::cout << std::endl;
		} else {
			std::cout << "Case #" << (i+1) << ": IMPOSSIBLE" << std::endl;
		}
	}

	return 0;
}
