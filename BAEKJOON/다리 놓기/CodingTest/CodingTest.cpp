#include <iostream>

using namespace std;

int DP[31][31];

int solve(int n, int m)
{
	if (DP[n][m] != 0)
	{
		return DP[n][m];
	}

	const int sub = m - n + 1;

	int rightSubCount = 1;
	while (rightSubCount <= sub)
	{
		DP[n][m] += solve(n - 1, m - rightSubCount);

		rightSubCount++;
	}

	return DP[n][m];
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= 30; i++)
	{
		DP[i][i] = 1;
		DP[1][i] = i;
	}

	int T;
	cin >> T;
	int N, M;

	while (T--)
	{
		cin >> N >> M;
		cout << solve(N, M) << '\n';
	}
	
	return 0;
}