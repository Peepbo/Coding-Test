#include <string>
#include <vector>
#include <queue>

using namespace std;

int N;
int Board[101][101];
bool Visited[101][101][2];

int dx[]{ 1,-1,0,0 };
int dy[]{ 0,0,-1,1 };

class Robot {
public:
	Robot(int x, int y, int t, int s) :
		x{ x }, y{ y }, time{ t }, state{ s }{}
public:
	int x;
	int y;
	int time;
	int state; //누움 0, 일어섬 1
};

bool isComplete(int x, int y) {
	return x == N && y == N;
}

bool isRange(int x, int y, int state) {
	if (x == 0 || x > N || y == 0 || y > N)return false;

	if (state == 0) {
		if (x - 1 == 0)return false;
	}
	else {
		if (y - 1 == 0)return false;
	}

	return true;
}

bool isCollision(int x, int y, int state) {
	if (state == 0)
		return Board[x][y] == 1 || Board[x - 1][y] == 1;
	else
		return Board[x][y] == 1 || Board[x][y - 1] == 1;
}

int BFS() {
	queue<Robot> q;
	q.push({ 2, 1, 0, 0 });
	Visited[1][1][0] = Visited[2][1][0] = 0;

	while (!q.empty()) {
		auto robot = q.front();
		q.pop();

		int x = robot.x;
		int y = robot.y;
		int t = robot.time;
		int s = robot.state;

		if (Visited[x][y][s])continue;
		Visited[x][y][s] = true;

		if (isComplete(x, y))return t;

		for (int i = 0; i < 4; i++) {
			int nX = x + dx[i];
			int nY = y + dy[i];

			if (!isRange(nX, nY, s))continue;
			if (isCollision(nX, nY, s))continue;

			q.push({ nX,nY,t + 1,s });

			if (s == 0) {
				if (dy[i] == 1) {//아래 이동 성공
					q.push({ x - 1, y + 1,t + 1, (s + 1) % 2 });
					q.push({ x, y + 1,t + 1, (s + 1) % 2 });
				}
				else if (dy[i] == -1) {//위 이동 성공
					q.push({ x, y, t + 1, (s + 1) % 2 });
					q.push({ x - 1, y, t + 1, (s + 1) % 2 });
				}
			}
			else {
				if (dx[i] == 1) {//오른쪽 이동 성공
					q.push({ x + 1,y,t + 1,(s + 1) % 2 });
					q.push({ x + 1,y - 1,t + 1,(s + 1) % 2 });
				}
				else if (dx[i] == -1) {//왼쪽 이동 성공
					q.push({ x,y - 1,t + 1,(s + 1) % 2 });
					q.push({ x, y, t + 1, (s + 1) % 2 });
				}
			}
		}
	}
}

int solution(vector<vector<int>> board) {
	N = board.size();
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			Board[x + 1][y + 1] = board[y][x];
		}
	}

	return BFS();
}

int main() {

	return 0;
}