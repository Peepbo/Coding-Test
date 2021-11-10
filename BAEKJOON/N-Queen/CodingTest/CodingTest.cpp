#include <iostream>

using namespace std;

int N, way;
int matrix[16][16];

void dfs(int y) {
	if (y == N) {
		way++;
		return;
	}

	for (int x = 0; x < N; x++) {
		if (matrix[y][x] == 0) {
			matrix[y][x]++;
			//down, leftDown, rightDown
			for (int j = 1; y + j < N; j++) {
				matrix[y + j][x]++;
				if (x + j < N) {
					matrix[y + j][x + j]++;
				}
				if (x - j >= 0) {
					matrix[y + j][x - j]++;
				}
			}

			dfs(y + 1);
			matrix[y][x]--;
			for (int j = 1; y + j < N; j++) {
				matrix[y + j][x]--;
				if (x + j < N) {
					matrix[y + j][x + j]--;
				}
				if (x - j >= 0) {
					matrix[y + j][x - j]--;
				}
			}
		}
	}
}

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	dfs(0);

	cout << way;
	return 0;
}