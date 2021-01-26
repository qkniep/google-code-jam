/*
 * Copyright (C) 2018 Quentin M. Kniep <hello@quentinkniep.com>
 * Distributed under terms of the MIT license.
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<long> readVector(int n) {
    vector<long> v;
    long tmp;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        v.push_back(tmp);
    }
    return v;
}

int main() {
    unsigned int T, N;

    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N;

        vector<long> v1 = readVector(N);
        vector<long> v2 = readVector(N);
        sort(v1.begin(), v1.end());  // sort vector 1 from small to large values
        sort(v2.rbegin(), v2.rend());  // sort vector 2 in reverse order

        // calculate the scalar product of these vectors
        long min = 0;
        for (int n = 0; n < N; n++) {
            min += v1[n] * v2[n];
        }

        cout << "Case #" << t << ": " << (min-1) << endl;
    }

    return 0;
}
