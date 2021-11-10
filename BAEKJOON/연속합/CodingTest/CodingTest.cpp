#include <iostream>

using namespace std;

int dp[100001];

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, now, MCS; // MCS : Maximum Consecutive Sum
	cin >> n >> now;
	MCS = now;

	dp[1] = now;
	for (int i = 2; i <= n; i++) {
		cin >> now;
		dp[i] = max(dp[i - 1] + now, now);
		MCS = max(MCS, dp[i]);
	}

	cout << MCS;
	return 0;
}