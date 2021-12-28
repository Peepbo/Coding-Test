#include <iostream>

using namespace std;

int factorial[11];

void initFactorial() {
	factorial[0] = factorial[1] = 1;
	for (int i = 2; i <= 10; i++) {
		factorial[i] = factorial[i - 1] * i;
	}
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	initFactorial();

	int N, K, top, down;
	cin >> N >> K;
	
	top = factorial[N];
	down = factorial[K] * factorial[N - K];

	cout << top / down;
}