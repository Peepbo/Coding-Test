#include <iostream>

#include <string>
#include <vector>

using namespace std;

#define MAX 1000000001

int solution(vector<int> a) {
	if (a.size() <= 2)return a.size();

	int answer = 2; //양쪽 풍선들은 무조건 살릴 수 있으므로 2를 추가한 상태로 시작
	int aSize = a.size(), select, lowCount;
	vector<int> leftMin(aSize, MAX), rightMin(aSize, MAX);

	//leftMin과 rightMin을 구해준다.

	//leftMin
	leftMin.front() = a.front();
	for (int i = 1; i < aSize; i++) {
		leftMin[i] = min(a[i], leftMin[i - 1]);
	}

	//rightMin
	rightMin.back() = a.back();
	for (int i = aSize - 2; i >= 0; i--) {
		rightMin[i] = min(a[i], rightMin[i + 1]);
	}

	//현재 값과 좌, 우 최솟값을 비교하여 lowCount를 계산한다.
	for (int i = 1; i < aSize - 1; i++) {
		select = a[i];

		lowCount = (select > leftMin[i - 1]) + (select > rightMin[i + 1]);
		if (lowCount == 2)continue;

		answer++;
	}

	return answer;
}

int main() {
	cout << solution({ 9,-1,-5 }) << endl;
	cout << solution({ -16,27,65,-2,58,-92,-71,-68,-61,-33 }) << endl;

	return 0;
}