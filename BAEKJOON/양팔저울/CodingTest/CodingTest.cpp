#include <iostream>

using namespace std;

int C, arr[31], dp[2][15001][30];

const int maximum(const int& a, const int& b, const int& c) {
	return max(a, max(b, c));
}

int solve(int sum, int idx) {
	if (sum == 0)return 2;
	const int AbsSum = abs(sum);
	const bool isPositive = sum > 0;

	if (AbsSum > 15000 || idx == C)return 1;
	if (dp[isPositive][AbsSum][idx] != 0)return dp[isPositive][AbsSum][idx];

	return dp[isPositive][AbsSum][idx] = maximum(
		solve(sum, idx + 1),
		solve(sum + arr[idx], idx + 1),
		solve(sum - arr[idx], idx + 1));
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int G, S;
	cin >> C;
	for (int i = 0; i < C; i++) {
		cin >> arr[i];
	}

	cin >> G;
	while (G--) {
		cin >> S;
		solve(S, 0) == 2 ? cout << "Y " : cout << "N ";
	}

	return 0;
}