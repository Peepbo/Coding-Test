#include <iostream>

#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

#define INF 999999999

const int mX[4]{ -1,1,0,0 };
const int mY[4]{ 0,0,-1,1 };

int matrix[101][101];
int dist[101][101];

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
	characterX *= 2;
	characterY *= 2;
	itemX *= 2;
	itemY *= 2;

	for (vector<int>& vec : rectangle) {
		vec[0] *= 2;
		vec[1] *= 2;
		vec[2] *= 2;
		vec[3] *= 2;

		for (int x = vec[0] + 1; x <= vec[2] - 1; x++) {
			for (int y = vec[1] + 1; y <= vec[3] - 1; y++) {
				matrix[y][x] = -1;
			}
		}

		for (int x = vec[0]; x <= vec[2]; x++) {
			if (matrix[vec[1]][x] != -1)
				matrix[vec[1]][x]++;
			if (matrix[vec[3]][x] != -1)
				matrix[vec[3]][x]++;
		}

		for (int y = vec[1] + 1; y <= vec[3] - 1; y++) {
			if (matrix[y][vec[0]] != -1)
				matrix[y][vec[0]]++;
			if (matrix[y][vec[2]] != -1)
				matrix[y][vec[2]]++;
		}
	}

	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			dist[i][j] = INF;
		}
	}

	//q : 위치, 비용
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(characterX, characterY, 0));

	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int cost = get<2>(q.front());
		q.pop();

		if (x == itemX && y == itemY) {
			return cost / 2;
		}

		for (int i = 0; i < 4; i++) {
			if (matrix[y + mY[i]][x + mX[i]] > 0) {
				if (dist[y + mY[i]][x + mX[i]] <= cost + 1)continue;
				dist[y + mY[i]][x + mX[i]] = cost + 1;

				q.push(make_tuple(x + mX[i], y + mY[i], cost + 1));
			}
		}
	}
}

int main(void) {
	/*
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (itemX == j && itemY == 100 - i) {
				cout << "▼";
			}
			else if (x == j && y == 100 - i) {
				cout << "★";
			}
			else if (matrix[100 - i][j] > 0) {
				cout << "■";
			}
			else {
				cout << "□";
			}
		}
		cout << '\n';
	}
	*/
	//solution({ { 1,1,7,4 }, { 3,2,5,5 }, { 4,3,6,9 }, { 2,6,8,8 } }, 1, 3, 7, 8);
	cout << solution({ {1, 1, 8, 4}, { 6, 3, 7, 7 } }, 6, 1, 5, 4);

	return 0;
}