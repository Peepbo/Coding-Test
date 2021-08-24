#include <iostream>
#include <vector>

using namespace std;

int numberRequired(const int& count, const int& sw) {
	if (count <= 0)return 0;
	return count / sw + (count % sw != 0 ? 1 : 0);
}

int solution(int n, vector<int> stations, int w)
{
	int answer = 0, sSize = stations.size(), count;
	int sw = 1 + w * 2; //한번에 설치할 때 전파되는 아파트 개수
	bool isFront, isBack;

	for (int i = 0; i < sSize; i++) {
		isFront = i - 1 < 0;
		isBack = i + 1 == sSize;

		//기지국의 앞쪽 검사
		count = isFront ? ((stations[i] - w) - 1) : ((stations[i] - w) - (stations[i - 1] + w)) - 1;
		answer += numberRequired(count, sw);

		//맨 뒤 기지국일 때 뒤 쪽 검사
		count = isBack ? (n - (stations[i] + w)) : 0;
		answer += numberRequired(count, sw);
	}

	return answer;
}

int main() {
	cout << solution(11, {4,11 }, 1);
	//cout << solution(9, { 2,5,8 }, 1);
	return 0;
}