#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> tree[100'001];
int parent[100'001];

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, a, b;
	cin >> N;

	// Init
	for (int i = 2; i <= N; i++) {
		cin >> a >> b;
		tree[a].emplace_back(b);
		tree[b].emplace_back(a);
	}

	stack<pair<int, int>> s; // now, last
	s.push({ 1, 1 });
	while (!s.empty()) {
		int now = s.top().first;
		int last = s.top().second;
		s.pop();

		for (const int& next : tree[now]) {
			if (next != last) {
				parent[next] = now;
				s.push({ next,now });
			}
		}
	}

	for (int i = 2; i <= N; i++) {
		cout << parent[i] << '\n';
	}

	return 0;
}