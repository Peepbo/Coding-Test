#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

vector<vector<int>> vertax;

string BipartiteGraphChecker(int maxSize) {
	map<int, bool> m; //index, isRed
	for (int i = 1; i <= maxSize; i++) {
		if (i != 1 && m.find(i) != m.end())continue;
		m[i] = true;

		queue<int> q;
		q.push(i);

		while (!q.empty()) {
			int idx = q.front();
			q.pop();

			for (const int& ver : vertax[idx]) {
				if (m.find(ver) != m.end() && m[ver] == m[idx]) {
					return "NO";
				}

				if (m.find(ver) == m.end()) {
					m[ver] = !m[idx];
					q.push(ver);
				}
			}
		}

	}
	return "YES";
}

int main(void) {
	int K, V, E, E1, E2, idx = 0;
	cin >> K;
	vector<string> output(K);

	while (K-- > 0) {
		cin >> V >> E;
		vertax.assign(V + 1, vector<int>());

		for (int i = 0; i < E; i++) {
			cin >> E1 >> E2;
			vertax[E1].emplace_back(E2);
			vertax[E2].emplace_back(E1);
		}

		output[idx++] = BipartiteGraphChecker(V);
	}

	for (const string& str : output) {
		cout << str << '\n';
	}

	return 0;
}