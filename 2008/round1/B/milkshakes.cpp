/*
 * Copyright (C) 2018 Quentin M. Kniep <hello@quentinkniep.com>
 * Distributed under terms of the MIT license.
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <queue>
#include <vector>

using namespace std;

struct preference {
    int maltedFlavor;
    int nonMaltedCount;
};

int main() {
    unsigned int T;

    cin >> T;

    for (int t = 1; t <= T; t++) {
        int numFlavors, numCustomers;
        cin >> numFlavors >> numCustomers;

        vector<preference> customerPreferences(numCustomers);
        vector<vector<int>> whoLikesFlavorNM(numFlavors);
        queue<int> openList;

        for (int c = 0; c < numCustomers; ++c) {
            int numLikedFlavors;
            cin >> numLikedFlavors;

            for (int f = 0; f < numLikedFlavors; ++f) {
                int flavor;
                bool malted;
                cin >> flavor >> malted;

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

        vector<bool> maltedBatches(numFlavors, false);
        bool success = true;

        while (!openList.empty()) {
            int currentCustomer = openList.front();
            openList.pop();
            int flavor = customerPreferences[currentCustomer].maltedFlavor - 1;

            if (!maltedBatches[flavor]) {
                maltedBatches[flavor] = true;

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
            cout << "Case #" << t << ": ";
            copy(begin(maltedBatches), end(maltedBatches), ostream_iterator<int>(cout, " "));
            cout << endl;
        } else {
            cout << "Case #" << t << ": IMPOSSIBLE" << endl;
        }
    }

    return 0;
}
