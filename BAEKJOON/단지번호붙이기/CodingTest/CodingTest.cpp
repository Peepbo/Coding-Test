#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int matrix[26][26];
bool visited[26][26];

const int mX[4]{ -1,1,0,0 };
const int mY[4]{ 0,0,-1,1 };

void dfs(const int& x, const int& y, int& num) {
	if (visited[x][y])return;
	visited[x][y] = true;

	num++;

	for (int i = 0; i < 4; i++) {
		int nX = x + mX[i];
		int nY = y + mY[i];

		if (nX < 0 || nX == N)continue;
		if (nY < 0 || nY == N)continue;
		if (matrix[nX][nY] != 1)continue;

		dfs(nX, nY, num);
	}
}

int main(void) {
	vector<int> house;
	string input;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> input;
		for (int j = 0; j < N; j++) {
			if (input[j] == '1') {
				matrix[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (matrix[i][j] == 1 && !visited[i][j]) {
				house.emplace_back(0);
				dfs(i, j, house.back());
			}
		}
	}

	sort(house.begin(), house.end());

	cout << house.size() << '\n';
	for (const int& cnt : house) {
		cout << cnt << '\n';
	}

	return 0;
}