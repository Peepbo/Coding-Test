#include <iostream>

using namespace std;

#define INF 999999999

int arr[501], sum[501];
int dp[501][501];

int solve(int left, int right) {
	if (dp[left][right] != INF) {
		return dp[left][right];
	}

	if (right == left) {
		dp[left][right] = 0;
	}

	else {
		int sub = right - left, area1, area2, areaSum;
		for (int i = 0; i < sub; i++) {
			area1 = solve(left, left + i);
			area2 = solve(left + i + 1, right);
			areaSum = sum[right] - sum[left - 1];

			dp[left][right] = min(dp[left][right], area1 + area2 + areaSum);
		}
	}

	return dp[left][right];
}

int main()
{
	int T, K;
	cin >> T;
	while (T--) {
		cin >> K;
		for (int i = 1; i <= K; i++) {
			cin >> arr[i];
			sum[i] = sum[i - 1] + arr[i];

			for (int j = 1; j <= K; j++) {
				dp[i][j] = INF;
			}
		}

		cout << solve(1, K) << '\n';
	}
	return 0;
}