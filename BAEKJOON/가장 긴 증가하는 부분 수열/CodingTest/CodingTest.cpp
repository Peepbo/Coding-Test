#include <iostream>

using namespace std;

int arr[1001];
int dp[1001];

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int N, tempN, idx = 1, answer = 1;
	cin >> N;
	tempN = N;
	while (tempN--)	{
		cin >> arr[idx++];
	}
	dp[1] = 1;
	for (int i = 2; i < idx; i++) {
		int maxCnt = 0;
		for (int j = 1; j < i; j++) {
			if (arr[i] > arr[j]) {
				maxCnt = max(maxCnt, dp[j]);
			}
		}
		dp[i] = 1 + maxCnt;
		answer = max(answer, dp[i]);
	}

	cout << answer;
	return 0;
}