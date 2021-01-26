/*
 * Copyright (C) 2018 Quentin M. Kniep <hello@quentinkniep.com>
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    string line;
    unsigned int T, S, Q;

    getline(cin, line);
    T = stoi(line);

    for (int t = 1; t <= T; t++) {
        int switches = 0;
        unordered_map<string, bool> searchEngines;

        getline(cin, line);
        S = stoi(line);

        for (int s = 0; s < S; s++) {
            getline(cin, line);
            searchEngines[line] = true;
        }

        getline(cin, line);
        Q = stoi(line);

        unordered_map<string, bool> possible(searchEngines);
        int numPossible= S;

        for (int q = 0; q < Q; q++) {
            getline(cin, line);
            if (possible[line]) {
                if (numPossible == 1) {
                    switches++;
                    numPossible = S;
                    possible = searchEngines;
                }
                possible[line] = false;
                numPossible--;
            }
        }

        cout << "Case #" << t << ": " << switches << endl;
    }
}
