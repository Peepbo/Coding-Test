#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int mX[4]{ -1,1,0,0 };
const int mY[4]{ 0,0,-1,1 };

int main(void) {
	vector<int> answer;
	int T, M, N, K, X, Y, count;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> M >> N >> K;
		vector<vector<bool>> matrix(M, vector<bool>(N));

		count = 0;

		for (int i = 0; i < K; i++) {
			cin >> X >> Y;

			matrix[X][Y] = true;
		}

		stack<pair<int,int>> s;
		for (int a = 0; a < M; a++) {
			for (int b = 0; b < N; b++) {
				s.push({ a,b });

				bool isFind = false;

				while (!s.empty()) {
					const int nX = s.top().first;
					const int nY = s.top().second;
					s.pop();

					if (matrix[nX][nY] == false)continue;
					matrix[nX][nY] = false;
					isFind = true;

					for (int j = 0; j < 4; j++) {
						const int nextX = nX + mX[j];
						const int nextY = nY + mY[j];

						if (nextX < 0 || nextX == M)continue;
						if (nextY < 0 || nextY == N)continue;
						if (matrix[nextX][nextY] == false)continue;

						s.push({ nextX,nextY });
					}
				}

				if (isFind) {
					count++;
				}
			}
		}

		answer.emplace_back(count);
	}

	for (const int& num : answer) {
		cout << num << '\n';
	}

	return 0;
}