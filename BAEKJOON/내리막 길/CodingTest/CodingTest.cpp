#include <iostream>

using namespace std;

int matrix[501][501], M, N;
int dp[501][501];
const int mX[4]{ -1,1,0,0 };
const int mY[4]{ 0,0,-1,1 };

int solve_topDown(int x, int y) {
	if (dp[y][x] != -1)return dp[y][x];
	if (x == 0 || y == 0 || x > N || y > M)return dp[y][x] = 0;

	int way = 0;
	for (int i = 0; i < 4; i++) {
		if (matrix[y][x] < matrix[y + mY[i]][x + mX[i]]) {
			dp[y + mY[i]][x + mX[i]] = solve_topDown(x + mX[i], y + mY[i]);
			way += dp[y + mY[i]][x + mX[i]];
		}
	}

	return dp[y][x] = way;
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> M >> N;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> matrix[i][j];
			dp[i][j] = -1;
		}
	}

	dp[1][1] = 1;

	cout << solve_topDown(N, M);
	return 0;
}