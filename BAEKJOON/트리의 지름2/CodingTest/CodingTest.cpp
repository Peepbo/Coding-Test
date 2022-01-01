#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> link[10'001];
int mIdx, mDist;

void dfs(int now, int last, int dist) {
	if (mDist < dist) {
		mDist = dist;
		mIdx = now;
	}

	for (const pair<int, int>& next : link[now]) {
		if (last != next.first) {
			dfs(next.first, now, dist + next.second);
		}
	}
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, a, b, c;
	cin >> n;

	// Init
	for (int i = 1; i < n; i++) {
		cin >> a >> b >> c;
		link[a].emplace_back(b, c);
		link[b].emplace_back(a, c);
	}

	dfs(1, 1, 0);
	dfs(mIdx, mIdx, 0);

	cout << mDist;
	return 0;
}