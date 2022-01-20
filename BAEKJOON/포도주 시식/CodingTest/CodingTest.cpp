#include <iostream>

using namespace std;

int arr[10001];
int dp[10001][2][3]; // 범위, 현재 위치 적용, 연속된 위치 개수

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, tempN, index = 1, answer = 0, lastMax;
	cin >> n;
	tempN = n;
	while (tempN--) {
		cin >> arr[index++];
	}
	
	dp[1][0][0] = 0;
	dp[1][1][1] = arr[1];
	lastMax = arr[1];

	for (int i = 2; i <= n; i++) {
		dp[i][1][1] = dp[i - 1][0][0] + arr[i];
		dp[i][1][2] = dp[i - 1][1][1] + arr[i];
		dp[i][0][0] = lastMax;

		lastMax = max(dp[i][1][1], dp[i][1][2]);
		lastMax = max(lastMax, dp[i][0][0]);
	}

	cout << lastMax;
	return 0;
}