#include <iostream>
#include <limits.h>
#include <cstring>

using namespace std;

pair<int, int> procession[501];
int dp[501][501];

int solve(int s, int e) {
	if (s == e)return 0;

	if (dp[s][e] != -1) {
		return dp[s][e];
	}

	int output = INT_MAX;
	for (int i = s; i < e; i++) {
		int solve1 = solve(s, i);
		int solve2 = solve(i + 1, e);

		output = min(output, solve1 + solve2 +
			procession[s].first * procession[i].second * procession[e].second);
	}

	return dp[s][e] = output;
}

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, r, c;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> r >> c;
		procession[i] = { r, c };
	}

	memset(dp, -1, sizeof(dp));
	cout << solve(1, N);
	return 0;
}