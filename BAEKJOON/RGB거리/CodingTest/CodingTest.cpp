#include <iostream>

using namespace std;

#define INF 1000001

int endSize, answer = INF;
int arr[1001][3];
int minValue[1001][3]; //idx,rgb

void dfs(int rgb, int value, int idx) {
	if (idx > endSize) {
		answer = min(answer, value);
		return;
	}

	for (int i = 0; i < 3; i++) {
		if (rgb == i)continue;
		if (minValue[idx][i] > value + arr[idx][i]) {
			minValue[idx][i] = value + arr[idx][i];
			dfs(i, minValue[idx][i], idx + 1);
		}
	}
}

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	endSize = N;

	int order = 1;
	while (N--) {
		for (int i = 0; i < 3; i++) {
			cin >> arr[order][i];
			minValue[order][i] = INF;
		}
		order++;
	}

	for (int i = 0; i < 3; i++) {
		dfs(i, arr[1][i], 2);
	}

	cout << answer;
	return 0;
}