#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

#define INF 999999999

const int mX[4]{ -1,1,0,0 };
const int mY[4]{ 0,0,-1,1 };

bool matrix[101][101];
int dist[101][101];

int main(void) {
	string input;
	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) { //y
		cin >> input;
		
		for (int j = 1; j <= M; j++) { //x
			dist[j][i] = INF;

			if (input[j - 1] == '1') {
				matrix[j][i] = true;
			}
		}
	}
	dist[1][1] = 0;

	queue<tuple<int, int, int>> q;
	q.push(make_tuple(1, 1, 1));
	while (!q.empty()) {
		const int x = get<0>(q.front());
		const int y = get<1>(q.front());
		const int c = get<2>(q.front());
		q.pop();

		if (x == M && y == N) {
			cout << c;
			break;
		}

		for (int i = 0; i < 4; i++) {
			const int nX = x + mX[i];
			const int nY = y + mY[i];

			if (nX < 1 || nX == M + 1)continue;
			if (nY < 1 || nY == N + 1)continue;
			if (matrix[nX][nY] == false)continue;
			if (dist[nX][nY] <= c + 1)continue;

			dist[nX][nY] = c + 1;
			q.push(make_tuple(nX, nY, c + 1));
		}
	}

	return 0;
}