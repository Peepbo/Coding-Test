#include <iostream>

using namespace std;

#define INF 100'001
int arr[INF];

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int N, S;
	int s, sum, len = INF;
	cin >> N >> S;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	s = 1;
	sum = 0;
	
	for (int e = 1; e <= N; e++) {
		sum += arr[e];

		if (sum < S)continue;

		while (sum - arr[s] >= S) {
			sum -= arr[s++];
		}

		len = min(len, e - s + 1);
	}

	cout << (len != INF ? len : 0);
	return 0;
}