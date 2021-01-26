/*
 * Copyright (C) 2018 Quentin M. Kniep <hello@quentinkniep.com>
 * Distributed under terms of the MIT license.
 */

#include <math.h>

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

// TODO fix this
float probabilityToHit(float f, float R, float t, float r, float g) {
    float inCircle = sqrt((R-t)*(R-t)/(R*R));
    float noString = inCircle * (g*g / ((2*r+g) * (2*r+g)));
    return 1.0 - inCircle + 1.0 - noString;
}

int main() {
    string line;
    unsigned int T;

    getline(cin, line);
    T = stoi(line);

    for (int tc = 1; tc <= T; tc++) {
        float f, R, t, r, g;
        scanf("%f %f %f %f %f\n", &f, &R, &t, &r, &g);
        float prob = probabilityToHit(f, R, t, r, g);
        cout << "Case #" << tc << ": " << fixed << setprecision(6) << prob << endl;
    }

    return 0;
}
