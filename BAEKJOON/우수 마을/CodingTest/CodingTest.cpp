#include <iostream>
#include <vector>

using namespace std;

vector<int> Link[10'001];
int Population[10'001];
int Dp[10'001][2];
int Visited[10'001];

void solve(int N)
{
	Visited[N] = true;

	Dp[N][0] = 0;
	Dp[N][1] = Population[N];

	for (const int& Next : Link[N])
	{
		if (!Visited[Next])
		{
			solve(Next);

			Dp[N][0] += max(Dp[Next][0], Dp[Next][1]);
			Dp[N][1] += Dp[Next][0];
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> Population[i];
	}
	int a, b;
	for (int i = 1; i <= N - 1; i++)
	{
		cin >> a >> b;
		Link[a].emplace_back(b);
		Link[b].emplace_back(a);
	}

	solve(1);
	const int ExcTotalPopulation = max(Dp[1][0], Dp[1][1]);
	cout << ExcTotalPopulation;
	return 0;
}