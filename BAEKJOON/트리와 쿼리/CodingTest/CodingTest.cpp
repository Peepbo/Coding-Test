#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> link;
int dp[100'001];

int solve(int node, int prev) {
	dp[node] = 1;
	for (const int& next : link[node]) {
		if (next != prev) {
			dp[node] += solve(next, node);
		}
	}

	return dp[node];
}

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, R, Q;
	int U, V;

	cin >> N >> R >> Q;
	link = vector<vector<int>>(N + 1);
	for (int i = 1; i < N; i++) {
		cin >> U >> V;
		link[U].emplace_back(V);
		link[V].emplace_back(U);
	}

	solve(R, 0);
	for (int i = 0; i < Q; i++) {
		cin >> U;
		cout << dp[U] << '\n';
	}
	return 0;
}