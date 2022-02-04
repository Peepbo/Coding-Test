#include <iostream>

using namespace std;

int A[101][101], B[101][101];
int N, M, K;

void matrixInit() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> A[i][j];
		}
	}
	cin >> M >> K;
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= K; j++) {
			cin >> B[i][j];
		}
	}
}

int sum(int a, int b, int c) {
	if (c > M)return 0;
	return A[a][c] * B[c][b] + sum(a, b, c + 1);
}

void matrixMultiple() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			cout << sum(i, j, 1) << ' ';
		}
		cout << '\n';
	}
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	matrixInit();
	matrixMultiple();

	return 0;
}