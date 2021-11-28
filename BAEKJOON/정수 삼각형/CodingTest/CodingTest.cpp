#include <iostream>

using namespace std;

const int mX[2]{ 0,1 };

int answer = -1;
int matrix[501][501]; // x, y (original data)
int maxSum[501][501]; // x, y (maxSum data)

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, tempN, nSize = 1;
	cin >> n;
	tempN = n;

	while (n) {
		for (int i = 1; i <= nSize; i++) {
			cin >> matrix[i][n];
			maxSum[i][n] = -1;
		}

		nSize++;
		n--;
	}
	maxSum[1][tempN] = matrix[1][tempN];

	nSize = 2;
	for (int y = tempN; y > 0; y--, nSize++) {
		for (int x = 1; x <= nSize; x++) {
			for (int i = 0; i < 2; i++) {
				int nX = x + mX[i];
				int nY = y - 1;
				
				if (maxSum[nX][nY] < maxSum[x][y] + matrix[nX][nY]) {
					maxSum[nX][nY] = maxSum[x][y] + matrix[nX][nY];
				}
			}
		}
	}

	for (int i = 1; i <= nSize; i++) {
		answer = max(answer, maxSum[i][1]);
	}
	cout << answer;
	return 0;
}