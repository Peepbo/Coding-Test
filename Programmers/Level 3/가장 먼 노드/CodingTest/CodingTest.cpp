#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

unordered_map<int, int> m;

int bfs(int n, const vector<vector<int>>& graph)
{
	vector<int> depth(n + 1, 0);
	vector<bool> visit(n + 1, false);
	int maxLen = 0;

	queue<int> q;
	depth[1] = 0;
	q.push(1);
	visit[1] = true;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		for (int i = 0; i < graph[now].size(); i++)
		{
			int next = graph[now][i];

			if (visit[next]) continue;
			visit[next] = true;

			depth[next] = depth[now] + 1;

			m[depth[next]]++;
			maxLen = max(maxLen, depth[next]);

			q.push(next);
		}
	}

	return m[maxLen];
}

int solution(int n, vector<vector<int>> edge) {
	vector<vector<int>> graph(n + 1);

	for (const auto& it : edge)
	{
		graph[it[0]].emplace_back(it[1]);
		graph[it[1]].emplace_back(it[0]);
	}

	return bfs(n, graph);
}

int main()
{
	cout << solution(6, { {3,6},{4,3},{3,2},{1,3},{1,2},{2,4},{5,2} });

	return 0;
}