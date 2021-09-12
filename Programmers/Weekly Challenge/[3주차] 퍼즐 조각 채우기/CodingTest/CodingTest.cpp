#include <iostream>

#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int maxSize;

struct Point {
	bool operator< (const Point& ptr) const {
		if (y != ptr.y)return y < ptr.y;
		return x < ptr.x;
	}
	Point operator+(const Point& ptr) const {
		return Point{ x + ptr.x, y + ptr.y };
	}
	bool operator==(const Point& ptr) const {
		return x == ptr.x && y == ptr.y;
	}
	Point operator-=(const Point& ptr) {
		x -= ptr.x;
		y -= ptr.y;
		return *this;
	}

	int x, y;
};

//Up Down Left Right
const Point movePos[4]{ {0,-1},{0,1},{-1,0},{1,0} };

class Block {
public:
	void rotate(vector<Point> pos) {
		sort(pos.begin(), pos.end());
		blockRotate[0] = pos;

		for (int i = 1; i < 4; i++) {
			for (const Point& ptr : blockRotate[i - 1]) {
				blockRotate[i].emplace_back(Point{ maxSize - ptr.y - 1, ptr.x });
			}

			//왼쪽 맨 위 좌표를 (0, 0) 기준으로 바꿔줘야 한다.
			//가장 y가 작으면서 x가 가장 작은 포인터가 기준
			sort(blockRotate[i].begin(), blockRotate[i].end());
			const Point refcol = blockRotate[i][0];
			for (Point& ptr : blockRotate[i]) {
				ptr -= refcol;
			}
		}
	}
public:
	vector<Point> blockRotate[4];
};

bool isSame(const vector<Point>& block1, const vector<Point>& block2) {
	for (int i = 0; i < block1.size(); i++) {
		if (block1[i] == block2[i])continue;

		return false;
	}
	return true;
}

void dfs(vector<vector<int>>& matrix, const Point& pos, const Point& newPos, const bool isTable, vector<Point>& output) {
	output.emplace_back(newPos);
	matrix[pos.y][pos.x] = (isTable ? 0 : 1);

	for (int i = 0; i < 4; i++) {
		const Point temp = pos + movePos[i];

		if (temp.x < 0 || temp.x == matrix.size() || temp.y < 0 || temp.y == matrix.size())continue;
		if (matrix[temp.y][temp.x] == (isTable ? 0 : 1))continue;

		const Point newTemp = newPos + movePos[i];

		dfs(matrix, temp, newTemp, isTable, output);
	}
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
	int answer = 0;
	int tableSize = table.size();
	maxSize = table.size();

	//key : 블록 개수, 블록 클래스 들
	map<int, vector<Block>> blockMap;
	//n개 짜리 블록 중에 찾기

	//테이블에 있는 모든 블록들을 dfs탐색을 통해 연결된 블록을 구한 뒤
	//맨 위, 좌측에 있는 블록을 기준블록으로 설정하고 나머지 블록들도 변환한다.
	//회전한 상태까지 구한다.
	for (int y = 0; y < tableSize; y++) {
		for (int x = 0; x < tableSize; x++) {
			if (table[y][x] == 0)continue;

			vector<Point> output;
			dfs(table, { x,y }, { 0,0 }, true, output);

			Block block;
			block.rotate(output);

			blockMap[output.size()].emplace_back(block);
		}
	}

	for (int y = 0; y < tableSize; y++) {
		for (int x = 0; x < tableSize; x++) {
			if (game_board[y][x] == 1)continue;

			vector<Point> output;
			dfs(game_board, { x,y }, { 0,0 }, false, output);
			sort(output.begin(), output.end());

			if (blockMap.find(output.size()) == blockMap.end())continue;

			bool isCollect = false;
			for (int i = 0; i < blockMap[output.size()].size(); i++) {
				auto num = blockMap[output.size()].size();
				Block& block = blockMap[output.size()][i];

				for (int j = 0; j < 4; j++) {
					if (!isSame(output, block.blockRotate[j]))continue;

					//같다
					isCollect = true;
					answer += output.size();

					//맵에 저장되어있는 블록을 제거해야됨
					blockMap[output.size()].erase(blockMap[output.size()].begin() + i);
					break;
				}

				if (isCollect) break;
			}
		}
	}

	return answer;
}

int main() {
	cout << solution({
	{0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0},
	{ 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0 },
	{ 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0 },
	{ 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1 },
	{ 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0 },
	{ 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1 },
	{ 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0 },
	{ 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0 },
	{ 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0 },
	{ 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0 },
	{ 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1 },
	{ 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0 } },
{
	{ 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1, 1},
	{ 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1 },
	{ 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0 },
	{ 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0 },
	{ 1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0 },
	{ 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
	{ 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1 },
	{ 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1 },
	{ 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1 },
	{ 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1 },
	{ 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1 },
	{ 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1 } });

	return 0;
}