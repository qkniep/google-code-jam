#include <array>
#include <iostream>
#include <set>
#include <vector>

std::set<int> panPrimes;
std::vector<std::array<int, 2>> factors;


int gcd(int a, int b) {
	while (b != 0) {
		int t = a % b;
		a = b;
		b = t;
	}
	return a;
}


char charForPrime(int prime) {
	int c = 0;
	for (int p : panPrimes) {
		if (p < prime) c++;
	}
	return 'A' + c;
}


bool findSolution(int id, int offset) {
	std::string s;
	int a, b;
	for (size_t i = 0; i < factors.size(); ++i) {
		a = factors[i][offset];
		b = factors[i][1-offset];
		s.push_back(charForPrime(a));
		if (i == factors.size()-1)     continue;
		if (factors[i+1][0] == b)      offset = 0;
		else if (factors[i+1][1] == b) offset = 1;
		else                           return false;
	}
	s.push_back(charForPrime(b));
	std::cout << "Case #" << id << ": " << s << std::endl;
	return true;
}


void findFactors(int L, const std::vector<int>& list) {
	factors.clear();
	panPrimes.clear();
	int f1, f2, toCopy = 0;
	for (int i = 0; i < L; ++i) {
		if (i < L-1) {
			if (list[i] == list[i+1]) {
				toCopy++;
				continue;
			}
			f1 = gcd(list[i], list[i+1]);
		}
		f2 = list[i] / f1;
		factors.push_back({f1, f2});
		for (; toCopy > 0; toCopy--) {
			factors.push_back({f1, f2});
		}
		panPrimes.insert(f1);
		panPrimes.insert(f2);
	}
}


int main() {
	int T;
	std::cin >> T;
	for (int t = 1; t <= T; ++t) {
		int N, L;
		std::cin >> N >> L;
		std::vector<int> list;
		for (int i = 0; i < L; ++i) {
			int x;
			std::cin >> x;
			list.push_back(x);
		}
		findFactors(L, list);
		if (!findSolution(t, 0)) {
			findSolution(t, 1);
		}
	}
}
