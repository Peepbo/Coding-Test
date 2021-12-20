#include <iostream>
#include <vector>

using namespace std;

vector<pair<int,int>> link[100'001];
int mIdx, mCost;

void dfs(int now, int last, int cost) {
	if (mCost < cost) {
		mCost = cost;
		mIdx = now;
	}

	for (const pair<int, int>& next : link[now]) {
		int nNext = next.first;
		int nCost = next.second;

		if (nNext != last) {
			dfs(nNext, now, cost + nCost);
		}
	}
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int V, idx, a, b;
	cin >> V;
	for (int i = 1; i <= V; i++) {
		cin >> idx;

		cin >> a;
		while (a != -1) {
			cin >> b;
			link[idx].emplace_back(a, b);
			cin >> a;
		}
	}

	dfs(1, 1, 0);
	dfs(mIdx, mIdx, 0);
	
	cout << mCost;
	return 0;
}