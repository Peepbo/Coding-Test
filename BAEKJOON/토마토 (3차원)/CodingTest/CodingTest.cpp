#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

//좌,우,앞,뒤,위,아래
const int mX[6]{ -1,1,0,0,0,0 };
const int mY[6]{ 0,0,1,-1,0,0 };
const int mZ[6]{ 0,0,0,0,-1,1 };

int matrix[101][101][101]; //x,y,z

int main(void) {
	string input;
	int M, N, H, total = 0, day = 0; //M : width, N : height
	cin >> M >> N >> H;
	const int maximum = M * N * H;

	queue<tuple<int,int,int>> q;

	for (int z = 0; z < H; z++) {
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				cin >> matrix[x][y][z];

				if (matrix[x][y][z] != 0) {
					total++;
					if (matrix[x][y][z] == 1) {
						q.push({ x,y,z });
					}
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
			const int x = get<0>(q.front());
			const int y = get<1>(q.front());
			const int z = get<2>(q.front());
			q.pop();

			for (int i = 0; i < 6; i++) {
				const int nX = x + mX[i];
				const int nY = y + mY[i];
				const int nZ = z + mZ[i];

				if (nX < 0 || nX == M)continue;
				if (nY < 0 || nY == N)continue;
				if (nZ < 0 || nZ == H)continue;
				if (matrix[nX][nY][nZ] != 0)continue;
				matrix[nX][nY][nZ] = matrix[x][y][z] + 1;

				total++;
				day = max(day, matrix[nX][nY][nZ]);

				q.push({ nX,nY,nZ });
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