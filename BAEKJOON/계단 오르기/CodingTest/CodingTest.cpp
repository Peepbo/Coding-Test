#include <iostream>

using namespace std;

int arr[301], maxScore[301][2], endSize;

void dfs(const int& index, const int& count, const int& sum) {
	if (index == endSize) return;

	// 연속 선택
	if (count == 1) {
		if (maxScore[index + 1][1] < sum + arr[index + 1]) {
			maxScore[index + 1][1] = sum + arr[index + 1];
			dfs(index + 1, 2, maxScore[index + 1][1]);
		}
	}
	// 점프 선택
	if (index + 2 <= endSize) {
		if (maxScore[index + 2][0] < sum + arr[index + 2]) {
			maxScore[index + 2][0] = sum + arr[index + 2];
			dfs(index + 2, 1, maxScore[index + 2][0]);
		}
	}
}

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, idx = 1;
	cin >> N;
	endSize = N;
	while (N--) {
		cin >> arr[idx++];
	}
	maxScore[endSize][0] = maxScore[endSize][1] = arr[endSize];

	dfs(1, 1, arr[1]);
	dfs(2, 1, arr[2]);

	cout << max(maxScore[endSize][0], maxScore[endSize][1]);
	return 0;
}