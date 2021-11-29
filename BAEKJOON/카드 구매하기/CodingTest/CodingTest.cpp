#include <iostream>

using namespace std;

int arr[1001], dp[1001];

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, k;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++) { // 사용하는 카드 종류
		for (int j = N; j >= 1; j--) { // 필요한 카드 개수

			k = 0;
			while (k * i <= j) {
				dp[j] = max(dp[j], dp[j - i * k] + arr[i] * k); // k개
				k++;
			}
		}
	}
	
	cout << dp[N];
	return 0;
}