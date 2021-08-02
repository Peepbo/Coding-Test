#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>>* Picture;
vector<vector<bool>>* Visited;
const int* M, * N;

struct Point {
	int x, y;
};

void solve(const int& target, const Point& pos, int& cost) {
	if (pos.x < 0 || pos.x >= *N || pos.y < 0 || pos.y >= *M)return;
	if ((*Visited)[pos.y][pos.x])return;
	if ((*Picture)[pos.y][pos.x] != target)return;

	(*Visited)[pos.y][pos.x] = true;
	cost++;

	solve(target, { pos.x - 1, pos.y }, cost); // left
	solve(target, { pos.x + 1, pos.y }, cost); // right
	solve(target, { pos.x, pos.y - 1 }, cost); // up
	solve(target, { pos.x, pos.y + 1 }, cost); // down
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0, max_size_of_one_area = 0;

	vector<vector<bool>> visited(m, vector<bool>(n, false));
	Picture = &picture;
	Visited = &visited;
	M = &m;
	N = &n;

	for (int y = 0; y < m; y++) {
		for (int x = 0; x < n; x++) {
			if (picture[y][x] == 0)continue;

			int cost = 0;
			//Pass the variable 'cost' as an address type
			solve(picture[y][x], { x, y }, cost);

			if (cost == 0)continue;

			number_of_area++;
			max_size_of_one_area = max(max_size_of_one_area, cost);
		}
	}

	return { number_of_area,max_size_of_one_area };
}

int main() {

	auto vec = solution(6, 4, { {1,1,1,0},{1,2,2,0},{1,0,0,1},{0,0,0,1},{0,0,0,3},{0,0,0,3} });
	cout << vec[0] << ' ' << vec[1];

	return 0;
}