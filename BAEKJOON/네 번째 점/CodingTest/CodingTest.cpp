#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(void) {
	int x, y;
	vector<pair<int, int>> pos(3);
	set<pair<int, int>> s;

	for (pair<int, int>& p : pos) {
		cin >> p.first >> p.second;
		s.insert(p);
	}

	for (int i = 0; i < 3; i++) {
		x = pos[i].first;

		for (int j = 0; j < 3; j++) {
			y = pos[j].second;

			if (s.find({ x,y }) == s.end()) {
				printf("%d %d", x, y);
				return 0;
			}
		}
	}

	return 0;
}