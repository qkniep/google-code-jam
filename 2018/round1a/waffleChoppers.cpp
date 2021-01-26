#include <iostream>
#include <string>
#include <vector>

int T, Y, X, H, V, SUM;
std::vector<std::string> waffle;


bool canSplit() {
	for (int y = 1; y < Y; ++y) {
		for (int x = 1; x < X; ++x) {
			bool q1 = false, q2 = false, q3 = false, q4 = false;
			int sum = 0;
			for (int yy = 0; yy < y; ++yy) {
				for (int xx = 0; xx < x; ++xx) {
					if (waffle[yy][xx] == '@') sum++;
				}
			}
			q1 = (sum == SUM / 4);
			sum = 0;
			for (int yy = 0; yy < y; ++yy) {
				for (int xx = x; xx < X; ++xx) {
					if (waffle[yy][xx] == '@') sum++;
				}
			}
			q2 = (sum == SUM / 4);
			sum = 0;
			for (int yy = y; yy < Y; ++yy) {
				for (int xx = 0; xx < x; ++xx) {
					if (waffle[yy][xx] == '@') sum++;
				}
			}
			q3 = (sum == SUM / 4);
			sum = 0;
			for (int yy = y; yy < Y; ++yy) {
				for (int xx = x; xx < X; ++xx) {
					if (waffle[yy][xx] == '@') sum++;
				}
			}
			q4 = (sum == SUM / 4);
			if (q1 && q2 && q3 && q4) return true;
		}
	}
	return false;
}


int main() {
	std::cin >> T;
	for (int t = 1; t <= T; ++t) {
		std::cin >> Y >> X >> H >> V;
		waffle.clear();
		for (int y = 0; y < Y; ++y) {
			std::string s;
			std::cin >> s;
			waffle.push_back(s);
		}
		SUM = 0;
		for (int y = 0; y < Y; ++y) {
			for (int x = 0; x < X; ++x) {
				if (waffle[y][x] == '@') SUM++;
			}
		}
		std::cout << "Case #" << t << ": ";
		if (canSplit()) std::cout << "POSSIBLE";
		else            std::cout << "IMPOSSIBLE";
		std::cout << std::endl;
	}
}
