#include <iostream>
#include <vector>

using namespace std;

vector<int> tree[501];
bool visited[501];

bool dfs(int idx, int last) {
	visited[idx] = true;

	for (const int& next : tree[idx]) {
		if (next == last)continue;
		if (visited[next])return false;
		if(!dfs(next, idx)) return false;
	}

	return true;
}

void print(int cnt, int T) {
	printf("Case %d: ", T);
	if (cnt == 0) {
		printf("No trees.\n");
	}
	else if (cnt == 1) {
		printf("There is one tree.\n");
	}
	else {
		printf("A forest of %d trees.\n", cnt);
	}
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m, a, b, cnt, T = 1;
	bool isTree;

	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0)break;
		cnt = 0;

		for (int i = 1; i <= n; i++) {
			tree[i].clear();
			visited[i] = false;
		}

		while (m--) {
			cin >> a >> b;
			tree[a].emplace_back(b);
			tree[b].emplace_back(a);
		}

		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				isTree = true;
				if (dfs(i, 0)) {
					cnt++;
				}
			}
		}

		print(cnt, T);
		T++;
	}


	return 0;
}