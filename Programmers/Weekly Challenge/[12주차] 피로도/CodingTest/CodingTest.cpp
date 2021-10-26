#include <iostream>
#include <string>
#include <vector>

using namespace std;

int answer, full;
vector<vector<int>> Dungeons;

void bruteForce(const int& k, const int& mask, const int& clear) {
	if (mask == full) {
		answer = max(answer, clear);
		return;
	}

	for (int i = 0; i < Dungeons.size(); i++) {
		if (mask & (1 << i))continue;

		const int nK = k >= Dungeons[i][0] ? k - Dungeons[i][1] : k;
		const int nMask = mask | (1 << i);
		const int nClear = k >= Dungeons[i][0] ? clear + 1 : clear;

		bruteForce(nK, nMask, nClear);
	}
}

int solution(int k, vector<vector<int>> dungeons) {
	Dungeons = dungeons;
	full = (1 << Dungeons.size()) - 1;
	bruteForce(k, 0, 0);

	return answer;
}

int main(void) {
	cout << solution(80, { { 80,20 }, { 50,40 }, { 30,10 } });

	return 0;
}