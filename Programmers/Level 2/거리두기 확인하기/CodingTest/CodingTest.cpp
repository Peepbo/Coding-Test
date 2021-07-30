#include <iostream>
#include <vector>

using namespace std;

struct Point {
	int x, y;
};

struct InspectionRecord {
	int manhattanDistance;
	vector<Point> inspectionLocation;
};

vector<Point> GetPeoples(const vector<string>& place) {
	vector<Point> peoples;

	for (int x = 0; x < 5; x++) {
		for (int y = 0; y < 5; y++) {
			if (place[x][y] == 'P')
				peoples.push_back({ x,y });
		}
	}

	return peoples;
}

InspectionRecord GetInspectionRecord(const Point& p1, const Point& p2) {
	vector<Point> location;

	if (p1.x != p2.x) {
		if (p1.x < p2.x)location.push_back({ 1,0 });
		else location.push_back({ -1,0 });
	}
	if (p1.y != p2.y) {
		if (p1.y < p2.y)location.push_back({ 0,1 });
		else location.push_back({ 0,-1 });
	}

	return { abs(p1.x - p2.x) + abs(p1.y - p2.y), location };
}

int CheckingQuarantineRules(const vector<Point>& peoples, const vector<string>& place) {
	int peopleSize = peoples.size();

	for (int i = 0; i < peopleSize; i++) {
		for (int j = i + 1; j < peopleSize; j++) {
			auto record = GetInspectionRecord(peoples[i], peoples[j]);

			if (record.manhattanDistance == 1)return 0;
			else if (record.manhattanDistance > 2)continue;

			//now hear manhattanDistance == 2
			const Point& standard = peoples[i];

			for (const Point& location : record.inspectionLocation) {
				if (place[standard.x + location.x][standard.y + location.y] != 'X')
					return 0;
			}
		}
	}

	return 1;
}

vector<int> solution(vector<vector<string>> places) {
	vector<int> answer;

	for (const auto& place : places) {
		//find People
		auto peoples = GetPeoples(place);

		answer.emplace_back(CheckingQuarantineRules(peoples, place));
	}

	return answer;
}

int main() {
	vector<string> place_A{ {"POOOP"},{"OXXOX"},{"OPXPX"},{"OOXOX"},{"POXXP"} };
	vector<string> place_B{ {"POOPX"},{"OXPXP"},{"PXXXO"},{"OXXXO"},{"OOOPP"} };
	vector<string> place_C{ {"PXOPX"},{"OXOXP"},{"OXPOX"},{"OXXOP"},{"PXPOX"} };
	vector<string> place_D{ {"OOOXX"},{"XOOOX"},{"OOOXX"},{"OXOOX"},{"OOOOO"} };
	vector<string> place_E{ {"PXPXP"},{"XPXPX"},{"PXPXP"},{"XPXPX"},{"PXPXP"} };
	vector <vector<string>> places{ place_A,place_B,place_C,place_D,place_E };

	auto vec = solution(places);

	for (const auto& it : vec) {
		cout << it << ' ';
	}

	return 0;
}