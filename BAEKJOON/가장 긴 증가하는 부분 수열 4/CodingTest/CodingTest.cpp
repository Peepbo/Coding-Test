#include <iostream>
#include <vector>

using namespace std;

int A[1'001], dp[1'001], high[1'001], start;

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	// Init
	int N, maximum = 1;
	cin >> N;
	start = N;

	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		dp[i] = 1;
	}

	for (int i = N - 1; i >= 1; i--) {
		for (int j = i + 1; j <= N; j++) {
			if (A[i] < A[j]) {
				if (dp[i] < dp[j] + 1) {
					dp[i] = dp[j] + 1;
					high[i] = j;

					if (maximum < dp[i]) {
						maximum = dp[i];
						start = i;
					}
				}
			}
		}
	}

	cout << maximum << '\n';
	while (high[start] != 0) {
		cout << A[start] << ' ';
		start = high[start];
	}
	cout << A[start];
	return 0;
}