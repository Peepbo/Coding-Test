#include <iostream>
#include <vector>

using namespace std;

struct Point {
	int x, y;
};

int matrix[10][10]; //[x][y]
vector<Point> points;
bool isClear;

const int cX[9]{ -1,0,1,-1,0,1,-1,0,1 }, cY[9]{ -1,-1,-1,0,0,0,1,1,1 };

bool check(Point ptr) {
	int choose = matrix[ptr.x][ptr.y];
	//가로 축 확인, 세로 축 확인
	for (int i = 1; i <= 9; i++) {
		if (ptr.x != i && matrix[i][ptr.y] == choose) {
			return false;
		}
		if (ptr.y != i && matrix[ptr.x][i] == choose) {
			return false;
		}
	}

	Point pivot; // center
	const int divX = (ptr.x - 1) / 3;
	pivot.x = divX * 3 + 2;
	
	const int divY = (ptr.y - 1) / 3;
	pivot.y = divY * 3 + 2;
	
	for (int i = 0; i < 9; i++) {
		int checkX = pivot.x + cX[i];
		int checkY = pivot.y + cY[i];
	
		if ((checkX != ptr.x && checkY != ptr.y) && matrix[checkX][checkY] == choose) {
			return false;
		}
	}

	return true;
}

void sudoku(int idx, int end) {
	if (idx == end) {
		for (int y = 1; y <= 9; y++) {
			for (int x = 1; x <= 9; x++) {
				cout << matrix[x][y] << ' ';
			}
			cout << '\n';
		}
		isClear = true;
		return;
	}

	for (int i = 1; i <= 9; i++) {
		matrix[points[idx].x][points[idx].y] = i;
		if (check(points[idx])) {
			sudoku(idx + 1, end);
		}
		if (isClear)return;
	}

	matrix[points[idx].x][points[idx].y] = 0;
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int input;

	for (int y = 1; y <= 9; y++) {
		for (int x = 1; x <= 9; x++) {
			cin >> input;

			if (input == 0) {
				points.emplace_back(Point{ x, y });
			}
			else {
				matrix[x][y] = input;
			}
		}
	}

	sudoku(0, points.size());
	return 0;
}