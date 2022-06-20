#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool visited[100'001];
int Order[100'001];
int O = 1;

void dfs(vector<int>& V, vector<vector<int>>& E, int R)
{
	Order[R] = O++;
	visited[R] = true;

	for (int Next : E[R])
	{
		if (!visited[Next])
		{
			dfs(V, E, Next);
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
		sort(E[i].begin(), E[i].end());
	}

	dfs(V, E, R);

	for (int i = 1; i <= N; i++)
	{
		cout << Order[i] << '\n';
	}
	return 0;
}