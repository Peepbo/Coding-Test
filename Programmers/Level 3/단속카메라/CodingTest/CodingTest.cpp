#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
	int answer = 1;

	sort(routes.begin(), routes.end());

	int entryPoint = routes[0][1];
	for (const auto& point : routes) {
		// 다음 차량의 진입 위치보다 현재 차량의 진출 위치가 더 작을 때
		// {-20,10},{12,20} / temp = 10, it[0] = 12, it[1] = 20
		if (entryPoint < point[0]) {
			// 한 카메라로 담을 수 없으므로 새 카메라를 추가하고
			answer++;
			// 저장된 진출 위치를 새로 받는다.
			entryPoint = point[1];
		}
		// 다음 차량의 진출 위치랑 현재 차량의 진출 위치가 같거나 더 클 때
		// {-20,10},{6,13} / temp = 10, it[0] = 6, it[1] = 13
		else if (entryPoint >= point[1]) {
			// 저장된 진출 위치를 새로 받는다.
			entryPoint = point[1];
		}
	}

	return answer;
}

int main() {
	cout << solution({ {-20,15},{-14,5},{-18,-13},{-5,-3} });

	return 0;
}