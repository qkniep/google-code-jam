/*
 * Copyright (C) 2021 Quentin M. Kniep <hello@quentinkniep.com>
 * Distributed under terms of the MIT license.
 */

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <algorithm>
#include <bitset>
#include <deque>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int solve(vector<vector<int>> m) {
    return 0;
}

int main() {
    // T: number of test cases, N: input size
    unsigned int T, N;

    cin >> T;

    for (int t = 1; t <= T; t++) {
        cin >> N;
        vector<vector<int>> m(N, vector<int>(N, 0));
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                cin >> m[y][x];
            }
        }
        cout << "Case #" << t << ": " << solve(m) << endl;
    }

    return 0;
}
