#include <iostream>

using namespace std;

int w[21][21][21];

int solveW(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) {
		return 1;
	} 

	if (a > 20 || b > 20 || c > 20) {
		a = 20;
		b = 20;
		c = 20;
	}

	if (w[a][b][c] == 0) {
		if (a < b && b < c) {
			w[a][b][c] = solveW(a, b, c - 1) + solveW(a, b - 1, c - 1) - solveW(a, b - 1, c);
		}
		else {
			w[a][b][c] = solveW(a - 1, b, c) + solveW(a - 1, b - 1, c) + solveW(a - 1, b, c - 1) - solveW(a - 1, b - 1, c - 1);
		}
	}

	return w[a][b][c];
}

int main(void) {
	for (int i = 1; i <= 20; i++) {
		for (int j = 1; j <= 20; j++) {
			for (int k = 1; k <= 20; k++) {
				solveW(i, j, k);
			}
		}
	}

	int a, b, c;
	while (true) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break;
		printf("w(%d, %d, %d) = %d\n", a, b, c, solveW(a, b, c));
	}

	return 0;
}