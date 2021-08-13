#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<string> Board;

struct Point {
	int x, y;
};

bool checkMove_recur(Point a, const Point& b, const int& choose) {
	if (choose == 0) { // a.x가 b.x와 같을 때 까지
		if (a.x == b.x)return true;
		if (Board[a.y][a.x] != Board[b.y][b.x] && Board[a.y][a.x] != '.')return false;

		if (a.x < b.x)
			return checkMove_recur({ a.x + 1,a.y }, b, choose);
		else
			return checkMove_recur({ a.x - 1, a.y }, b, choose);
	}

	else { // a.y가 b.y와 같을 때 까지
		if (a.y == b.y)return true;
		if (Board[a.y][a.x] != Board[b.y][b.x] && Board[a.y][a.x] != '.')return false;

		if (a.y < b.y)
			return checkMove_recur({ a.x, a.y + 1 }, b, choose);
		else
			return checkMove_recur({ a.x, a.y - 1 }, b, choose);
	}
}

bool checkMove(const Point& a, const Point& b) {
	int length = abs(a.x - b.x) + abs(a.y - b.y);

	if (length == 1)return true;

	// 길이가 2이상일 때
	const char ch = Board[a.y][a.x];
	// case 1 : a.x를 b.x로 이동하고, a.y를 b.y로 이동하는게 가능한지
	if (checkMove_recur(a, b, 0) && checkMove_recur({ b.x,a.y }, b, 1)) return true;
	// case 2 : a.y를 b.y로 이동하고, a.x를 b.x로 이동하는게 가능한지
	if (checkMove_recur(a, b, 1) && checkMove_recur({ a.x,b.y }, b, 0)) return true;
	// 위 두 경우에 해당하지 않으면 이동할 수 없음
	return false;
}

string solution(int m, int n, vector<string> board) {
	string answer = "";

	map<char, vector<Point>> mp;

	Board = board;

	for (int y = 0; y < m; y++) {
		for (int x = 0; x < n; x++) {
			if (isalpha(Board[y][x])) {
				mp[Board[y][x]].push_back({ x,y });
			}
		}
	}

	while (!mp.empty()) {
		bool isMatch = false;

		for (auto& tiles : mp) {
			char ch = tiles.first;
			Point pt0 = tiles.second[0];
			Point pt1 = tiles.second[1];

			if (checkMove(pt0, pt1)) {
				Board[pt0.y][pt0.x] = '.';
				Board[pt1.y][pt1.x] = '.';

				answer += ch;
				mp.erase(ch);
				isMatch = true;
				break;
			}
		}

		if (!isMatch) return "IMPOSSIBLE";
	}

	return answer;
}

int main()
{
	//cout << solution(3, 3, { "DBA", "C*A", "CDB" }) << endl;
	//cout << solution(2, 4, { "NRYN", "ARYA" }) << endl;
	//cout << solution(4, 4, { ".ZI.", "M.**","MZU.",".IU." }) << endl;
	//cout << solution(2, 2, { "AB", "BA" }) << endl;
	cout << solution(5, 5, { "FGHEI","BAB..","D.C*.","CA..I","DFHGE" }) << endl;
}