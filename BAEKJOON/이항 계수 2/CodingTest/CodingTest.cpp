#include <iostream>

using namespace std;

#define MAXIMUM 1001
#define MOD 10'007

int pTriangle[MAXIMUM][MAXIMUM];

void pascalTriangle(int N, int K) {
	pTriangle[0][0] = 1;
	for (int i = 1; i < MAXIMUM; i++) {
		pTriangle[i][0] = pTriangle[i][i] = 1;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= i; j++) {
			pTriangle[i][j] = (pTriangle[i - 1][j] + pTriangle[i - 1][j - 1]) % MOD;
		}
	}
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, K;
	cin >> N >> K;
	pascalTriangle(N, K);

	cout << pTriangle[N][K];
}