#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int N, K, num = 0;
	cin >> N >> K;

	vector<int> coins(N);
	for (int i = 0; i < N; i++) {
		cin >> coins[N - (i + 1)];
	}

	for (const int& coin : coins) {
		if (K == 0)break;

		if (K >= coin) {
			num += K / coin;
			K %= coin;
		}
	}

	cout << num;

	return 0;
}