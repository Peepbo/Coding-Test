#include <iostream>

using namespace std;

#define MAXIMUM 2'000'000'000

int N, A[12], oper[4]; // +.-.x./
int maxValue = -MAXIMUM, minValue = MAXIMUM;

int cul(int a, int b, int operIdx) {
	switch (operIdx)
	{
	case 0: // +
		return a + b;
	case 1: // -
		return a - b;
	case 2: // x
		return a * b;
	case 3: // /
		if (a < 0) {
			int tA = -a;
			return -(tA / b);
		}
		return a / b;
	}
}

void solve(int index, int result) {
	if (index > N) {
		maxValue = max(maxValue, result);
		minValue = min(minValue, result);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (oper[i] > 0) {
			int nextResult = cul(result, A[index], i);
			oper[i]--;
			solve(index + 1, nextResult);
			oper[i]++;
		}
	}
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> oper[i];
	}
	solve(2, A[1]);

	cout << maxValue << '\n' << minValue;
	return 0;
}