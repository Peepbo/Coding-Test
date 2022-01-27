#include <iostream>
#include <vector>

using namespace std;

pair<int, int> fibonacci[41];

const pair<int, int> sum(const pair<int, int>& p1, const pair<int, int>& p2) {
	return { p1.first + p2.first, p1.second + p2.second };
}

int main(void) {
	fibonacci[0] = { 1,0 };
	fibonacci[1] = { 0,1 };
	for (int i = 2; i <= 40; i++) {
		fibonacci[i] = sum(fibonacci[i - 1], fibonacci[i - 2]);
	}

	int T, N;
	cin >> T;
	while (T--) {
		cin >> N;
		printf("%d %d\n", fibonacci[N].first, fibonacci[N].second);
	}

	return 0;
}