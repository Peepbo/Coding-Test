#include <iostream>

#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct compare {
	bool operator()(vector<int> a, vector<int> b) {
		return a[1] > b[1];
	}
};

int solution(vector<vector<int>> jobs) {
	int answer = 0, index = 0, nowTime = 0, size = jobs.size();

	sort(jobs.begin(), jobs.end());
	priority_queue<vector<int>, vector<vector<int>>, compare> q;

	while (index < size || !q.empty()) {
		//범위를 벗어나지 않으며, 현재 시점에서 해당 작업을 진행할 수 있을 때
		if (index < size && jobs[index][0] <= nowTime) {
			q.push(jobs[index++]);
			continue;
		}

		if (!q.empty()) {
			nowTime += q.top()[1]; // 끝나는 시간을 t에 더함
			answer += nowTime - q.top()[0]; // 현재시간 - 지연시간으로 작업시간을 계산
			q.pop(); // 현재 작업을 마무리지음
		}

		else { // 작업중이 아닐 때
			nowTime = jobs[index][0]; // 시점을 다음 시점으로 넘김
		}
	}

	return answer / size;
}

int main() {
	cout << solution({ { 0,3 }, { 1,9 }, { 2,6 } });
	return 0;
}