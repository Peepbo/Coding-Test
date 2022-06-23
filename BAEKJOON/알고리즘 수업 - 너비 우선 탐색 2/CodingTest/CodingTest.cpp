#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool visited[100'001];
int Order[100'001];
int O = 1;

void bfs(vector<int>& V, vector<vector<int>>& E, int R)
{
	for (int Close : E[R])
	{
		visited[Close] = false;
	}
	Order[R] = O++;
	visited[R] = true;

	queue<int> Q;
	Q.push(R);
	while (!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		for (int v : E[u])
		{
			if (!visited[v])
			{
				Order[v] = O++;
				visited[v] = true;
				Q.push(v);
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M, R;
	int u, v;
	cin >> N >> M >> R;

	vector<int> V(N + 1);
	vector<vector<int>> E(N + 1);

	for (int i = 1; i <= N; i++)
	{
		V[i] = i;
	}
	while (M--)
	{
		cin >> u >> v;
		E[u].emplace_back(v);
		E[v].emplace_back(u);
	}

	for (int i = 1; i <= N; i++)
	{
		sort(E[i].begin(), E[i].end(), greater<>());
	}

	bfs(V, E, R);

	for (int i = 1; i <= N; i++)
	{
		cout << Order[i] << '\n';
	}
	return 0;
}