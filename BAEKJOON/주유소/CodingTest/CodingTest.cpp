#include <iostream>
#include <vector>

using namespace std;

#define INF 1'000'000'000

int dist[100'001];

long long solve() {
	int N;
	long long price, lastMin = INF, answer = 0;
	cin >> N;
	for (int i = 1; i <= N - 1; i++) {
		cin >> dist[i];
	}

	for (int i = 1; i <= N - 1; i++) {
		cin >> price;

		lastMin = min(lastMin, price);

		answer += lastMin * dist[i];
	}

	return answer;
}

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cout << solve();
	return 0;
}