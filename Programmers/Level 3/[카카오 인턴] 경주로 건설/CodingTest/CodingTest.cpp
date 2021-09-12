#include <iostream>

#include <string>
#include <vector>
#include <queue>

using namespace std;

#define INF 999999999

//u,d,l,r
const int mX[4]{ 0,0,-1,1 };
const int mY[4]{ -1,1,0,0 };
const int oppDir[4]{ 1,0,3,2 };

int matrix[25][25][4];

struct Car
{
	int x, y, dir, cost;
};

int solution(vector<vector<int>> board) {
	const int maxSize = board.size();
	int answer = INF;

	for (int i = 0; i < maxSize; i++) {
		for (int j = 0; j < maxSize; j++) {
			for (int k = 0; k < 4; k++) {
				matrix[i][j][k] = INF;
			}
		}
	}

	for (int i = 0; i < 4; i++) {
		matrix[0][0][i] = 0;
	}

	queue<Car> q;
	q.push({ 0, 0, 1, 0 });
	q.push({ 0, 0, 3, 0 });

	while (!q.empty()) {
		const Car car = q.front();
		q.pop();

		if (car.x == maxSize - 1 && car.y == maxSize - 1) {
			answer = min(answer, car.cost);
			continue;
		}

		for (int i = 0; i < 4; i++) {
			if (i == oppDir[car.dir])continue;

			Car temp = car;
			temp.x += mX[i];
			temp.y += mY[i];

			if (temp.x < 0 || temp.y < 0 || temp.x == maxSize || temp.y == maxSize) continue;
			if (board[temp.y][temp.x] == 1)continue;
			if (temp.dir != i) {
				temp.dir = i;
				temp.cost += 500;
			}
			temp.cost += 100;

			if (matrix[temp.y][temp.x][temp.dir] < temp.cost)continue;
			matrix[temp.y][temp.x][temp.dir] = temp.cost;
			q.push(temp);
		}
	}

	return answer;
}

int main() {

	return 0;
}