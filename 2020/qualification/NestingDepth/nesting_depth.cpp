/*
 * Copyright (C) 2021 Quentin M. Kniep <hello@quentinkniep.com>
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <string>

using namespace std;

int main() {
    unsigned int T;

    cin >> T;

    for (int t = 1; t <= T; ++t) {
        int depth = 0;
        string input, output = "";

        cin >> input;

        for (char c : input) {
            int digit = c - '0';
            if (depth < digit) output.append(digit-depth, '(');
            if (depth > digit) output.append(depth-digit, ')');
            depth = digit;
            output.push_back(c);
        }
        output.append(depth, ')');

        cout << "Case #" << t << ": " << output << endl;
    }
}
