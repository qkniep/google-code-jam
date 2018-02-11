/*
 * minScalarProduct.cpp
 * Copyright (C) 2018 Quentin Kniep <hello@quentinkniep.com>
 *
 * Distributed under terms of the MIT license.
 */

#include <algorithm>
#include <iostream>
#include <vector>


std::vector<long> readVector(int n) {
	std::vector<long> v;
	for (int i = 0; i < n; ++i) {
		long tmp;
		std::cin >> tmp;
		v.push_back(tmp);
	}
	return v;
}

int main() {
	int t;
	std::cin >> t;

	for (int i = 0; i < t; ++i) {
		int n;
		std::cin >> n;

		std::vector<long> v1 = readVector(n);
		std::vector<long> v2 = readVector(n);
		std::sort(v1.begin(), v1.end());  // sort vector 1 from small to large values
		std::sort(v2.rbegin(), v2.rend());  // sort vector 2 in reverse order

		// calculate the scalar product of these vectors
		long min = 0;
		for (int k = 0; k < n; ++k) {
			min += v1[k] * v2[k];
		}

		std::cout << "Case #" << (i+1) << ": " << min << std::endl;
	}

	return 0;
}
