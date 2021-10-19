#include <iostream>
#include <queue>

using namespace std;

const int mX[4]{ -1,1,0,0 };
const int mY[4]{ 0,0,-1,1 };

int matrix[1001][1001];

int main(void) {
	string input;
	int M, N, total = 0, day = 0; //M : width, N : height
	cin >> M >> N;
	const int maximum = M * N;

	queue<pair<int, int>> q;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> matrix[x][y];

			if (matrix[x][y] != 0) {
				total++;
				if (matrix[x][y] == 1) {
					q.push({ x,y });
				}
			}
		}
	}

	if (total == 0) {
		cout << -1;
	}
	else if (total == maximum) {
		cout << 0;
	}
	else {
		while (!q.empty()) {
			const int x = q.front().first;
			const int y = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				const int nX = x + mX[i];
				const int nY = y + mY[i];

				if (nX < 0 || nX == M)continue;
				if (nY < 0 || nY == N)continue;
				if (matrix[nX][nY] != 0)continue;
				matrix[nX][nY] = matrix[x][y] + 1;

				total++;
				day = max(day, matrix[nX][nY]);

				q.push({ nX,nY });
			}
		}

		if (total == maximum) {
			cout << day - 1;
		}
		else {
			cout << -1;
		}
	}

	return 0;
}