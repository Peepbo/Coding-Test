#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(void) {
	int N, L, a, b, now, cnt = 0;
	cin >> N >> L;

	vector<vector<int>> graph(N + 1);
	vector<bool> visit(N + 1);

	for (int i = 0; i < L; i++) {
		cin >> a >> b;
		graph[a].emplace_back(b);
		graph[b].emplace_back(a);
	}

	stack<int> s;
	s.push(1);
	visit[1] = true;

	while (!s.empty()) {
		now = s.top();
		s.pop();

		for (int next : graph[now]) {
			if (visit[next])continue;
			visit[next] = true;

			cnt++;

			s.push(now);
			s.push(next);
			break;
		}
	}

	cout << cnt;

	return 0;
}