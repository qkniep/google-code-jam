/*
 * Copyright (C) 2021 Quentin M. Kniep <hello@quentinkniep.com>
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        string output;
        int goalX, goalY;
        cin >> goalX >> goalY;

        bool impossible = false;

        for (int i = 1; i <= abs(goalX) || i <= abs(goalY); i *= 2) {
            if (((goalX & i) & (goalY & i)) && (i == 1 || i * 2 <= abs(goalX) || i * 2 <= abs(goalY))) {
                impossible = true;
                break;
            } else if (!((goalX & i) | (goalY & i))) {
                impossible = true;
                break;
            }
        }

        for (int d1 = 0; d1 < ) {
            for (int d1 = 0; d1 < ) {
            }
        }

        if (impossible) {
            output = "IMPOSSIBLE";
        } else {
        }

        cout << "Case #" << t << ": " << output << endl;
    }
}
