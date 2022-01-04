#include <iostream>

using namespace std;

long long P[101] { 0,1,1,1,2,2 };

int main(void) {
	for (int i = 6; i <= 100; i++) {
		P[i] = P[i - 1] + P[i - 5];
	}

	int T, N;
	cin >> T;

	while (T--) {
		cin >> N;
		cout << P[N] << '\n';
	}

	return 0;
}