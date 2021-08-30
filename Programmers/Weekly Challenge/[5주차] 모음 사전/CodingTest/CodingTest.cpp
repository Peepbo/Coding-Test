#include <iostream>

#include <string>
#include <vector>
#include <map>

using namespace std;

string Arr[6]{ "","A","E","I","O","U" };
map<string, int> Map;
int MapSize = 1;

void dfs_recur(string write, bool isBlank, int number) {
	if (number == 5) {
		Map[write] = MapSize++;
		return;
	}

	for (int i = 0; i < 6; i++) {
		dfs_recur(write + Arr[i], i == 0, number + 1);
		if (isBlank) break;
	}
}

int solution(string word) {
	int answer = 0;

	for (int i = 1; i < 6; i++) {
		dfs_recur(Arr[i], false, 1);
	}

	return Map[word];
}

int main() {
	cout << solution("I");

	return 0;
}