#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int main(void) {
	int N, M, V, a, b, now;
	cin >> N >> M >> V;

	vector<vector<int>> graph(N + 1);
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		graph[a].emplace_back(b);
		graph[b].emplace_back(a);
	}

	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	stack<int> s;
	queue<int> q;

	//dfs
	s.push(V);
	vector<bool> visited(N + 1);
	visited[V] = true;
	cout << V << ' ';
	while (!s.empty()) {
		now = s.top();
		s.pop();
	
		for (const int& next : graph[now]) {
			if (visited[next])continue;
			visited[next] = true;
			cout << next << ' ';

			s.push(now);
			s.push(next);
			break;
		}
	}
	cout << '\n';

	//bfs
	q.push(V);
	visited.assign(N + 1, false);
	visited[V] = true;

	while (!q.empty()) {
		now = q.front();
		q.pop();

		cout << now << ' ';

		for (int next : graph[now]) {
			if (visited[next])continue;
			visited[next] = true;
			q.push(next);
		}
	}

	return 0;
}