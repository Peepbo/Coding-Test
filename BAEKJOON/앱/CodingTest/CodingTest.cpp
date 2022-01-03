#include <iostream>
#include <cstring>

using namespace std;

int memory[100];
int cost[100];
int dp[100][10'001]; // i번 앱부터 조사해서 j비용으로 확보한 최대 메모리
int N, M;

int dfs(int curCost, int idx) {
	if (idx >= N) return 0;

	// dp에 저장된 데이터를 불러옴
	int& best = dp[idx][curCost];

	// 만약 -1(default)이 아니라면(이미 구했다면) 반환해줌
	if (best != -1) return best;

	// 현재 앱을 켜놨을 때 최대 메모리
	best = dfs(curCost, idx + 1);

	// 현재 앱을 종료해도 remain이 유효할 때, 종료해도 상관없을 때
	if (cost[idx] <= curCost) {
		int exitCase = dfs(curCost - cost[idx], idx + 1) + memory[idx];
		best = max(best, exitCase);
	}

	return best;
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int sum = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> memory[i];
	}

	for (int i = 0; i < N; i++) {
		cin >> cost[i];
		sum += cost[i];
	}
	memset(dp, -1, sizeof(dp));

	for (int c = 0; c <= sum; c++) {
		int best = dfs(c, 0);
		if (best >= M) {
			cout << c;
			break;
		}
	}
}