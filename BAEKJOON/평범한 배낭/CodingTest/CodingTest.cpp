#include <iostream>

using namespace std;

pair<int, int> arr[101];
int dp[100'001];

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, K, W, V;
	int nW, nV;

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> W >> V;
		arr[i] = { W,V };
	}

	for (int n = 1; n <= N; n++) {
		for (int w = K; w >= 1; w--) {
			nW = arr[n].first;
			nV = arr[n].second;

			if (w - nW >= 0) {
				dp[w] = max(dp[w - nW] + nV, dp[w]);
			}
		}
	}

	cout << dp[K];
	return 0;
}