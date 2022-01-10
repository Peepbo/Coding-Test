#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> link;
vector<bool> visited;
int result;

void bfs(int idx) {
	visited[idx] = true;

	for (const int& next : link[idx]) {
		if (visited[next])continue;

		result++;
		bfs(next);
	}
}

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T, N, M, a, b;
	cin >> T;
	while (T--) {
		cin >> N >> M;
		link = vector<vector<int>>(N + 1);
		visited = vector<bool>(N + 1);
		result = 0;

		while (M--) {
			cin >> a >> b;
			link[a].emplace_back(b);
			link[b].emplace_back(a);
		}

		bfs(1);
		cout << result << '\n';
	}

    return 0;
}