/*
 * Copyright (C) 2021 Quentin M. Kniep <hello@quentinkniep.com>
 * Distributed under terms of the MIT license.
 */

#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    unsigned int T, N;

    cin >> T;

    for (int t = 1; t <= T; ++t) {
        cin >> N;

        vector<int> vec = vector<int>(N*N);

        int value;
        for (int y = 0; y < N; ++y) {
            for (int x = 0; x < N; ++x) {
                cin >> value;
                vec[y*N+x] = value;
            }
        }

        int trace = 0, rows = 0, cols = 0;
        for (int i = 0; i < N; ++i) {
            trace += vec[i*N+i];

            set<int> row, col;
            for (int j = 0; j < N; ++j) {
                int row_val = vec[i*N+j];
                if (row.find(row_val) != row.end()) {
                    rows += 1;
                    break;
                }
                row.insert(row_val);
            }

            for (int j = 0; j < N; ++j) {
                int col_val = vec[j*N+i];
                if (col.find(col_val) != col.end()) {
                    cols += 1;
                    break;
                }
                col.insert(col_val);
            }
        }

        cout << "Case #" << t << ": " << trace << " " << rows << " " << cols << endl;
    }
}
