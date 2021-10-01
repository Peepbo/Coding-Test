#include <iostream>
#include <vector>
#include <set>

using namespace std;

int MaxSize, MaxRange;

set<vector<int>> output;
set<int> bitSet;

void bfs(vector<int>& num, int bit) {
	if (num.size() == MaxSize) {
		if (bitSet.find(bit) == bitSet.end()) {
			bitSet.insert(bit);

			output.insert(num);
		}
		
		return;
	}

	for (int i = 1; i <= MaxRange; i++) {
		if (bit & (1 << i))continue;

		num.emplace_back(i);
		bfs(num, bit | (1 << i));
		num.pop_back();
	}
}

int main(void) {
	int N, M;
	cin >> N >> M;

	MaxSize = M;
	MaxRange = N;

	for (int i = 1; i <= N; i++) {
		vector<int> vec{ i };
		bfs(vec, (1 << i));
	}

	for (const auto& v : output) {
		for (const auto& i : v) {
			cout << i << ' ';
		}
		cout << '\n';
	}

	return 0;
}