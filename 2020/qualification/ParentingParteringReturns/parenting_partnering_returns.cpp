/*
 * Copyright (C) 2021 Quentin M. Kniep <hello@quentinkniep.com>
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<pair<int, int>, int> pi;

int main() {
    unsigned int T, N;

    cin >> T;

    for (int t = 1; t <= T; ++t) {
        string output = "";

        cin >> N;

        output.append(N, 'X');

        priority_queue<pi, vector<pi>, greater<pi>> heap;
        for (int n = 0; n < N; ++n) {
            int s, e;
            cin >> s >> e;
            heap.push(make_pair(make_pair(s, e), n));
        }

        int C = 0, J = 0;
        while (!heap.empty()) {
            pi te = heap.top();
            int s = te.first.first, e = te.first.second, n = te.second;
            if (s < C && s < J) {
                output = "IMPOSSIBLE";
                break;
            } else if (s >= C && (s < J || C >= J)) {
                output[n] = 'C';
                C = e;
            } else if (s >= J && (s < C || J > C)) {
                output[n] = 'J';
                J = e;
            }
            heap.pop();
        }

        cout << "Case #" << t << ": " << output << endl;
    }
}
