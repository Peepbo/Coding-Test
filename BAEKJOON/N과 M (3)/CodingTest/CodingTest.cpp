#include <iostream>
#include <vector>
#include <set>

using namespace std;

int MaxSize, MaxRange;

vector<vector<int>> output;

void bfs(vector<int>& num) {
	if (num.size() == MaxSize) {
		output.emplace_back(num);
		
		return;
	}

	for (int i = 1; i <= MaxRange; i++) {
		num.emplace_back(i);
		bfs(num);
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
		bfs(vec);
	}

	for (const auto& v : output) {
		for (const auto& i : v) {
			cout << i << ' ';
		}
		cout << '\n';
	}

	return 0;
}