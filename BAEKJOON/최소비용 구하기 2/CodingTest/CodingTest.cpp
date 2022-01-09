#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

#define INF 100'000'001
#define pii pair<int,int>
#define pqiig priority_queue<pii, vector<pii>, greater<>>

vector<vector<pair<int,int>>> link;
vector<int> prevIdx;
stack<int> reversePath;
int n, m;

int dijkstra(int start, int end) {
	int cIdx, cCost; // current
	int nIdx, nCost; // next

	// first = cost, second = next
	vector<int> dist(n + 1, INF);
	dist[start] = 0;

	pqiig pq;
	pq.push({ 0, start });

	while (!pq.empty()) {
		cCost = pq.top().first;
		cIdx = pq.top().second;
		pq.pop();

		// 간선이 중복되는 경우; 현재 간선이 최단 간선이 아니면 continue
		if (dist[cIdx] < cCost)continue;

		for (const auto& pairData : link[cIdx]) {
			nCost = cCost + pairData.first;
			nIdx = pairData.second;

			if (dist[nIdx] > nCost) {
				dist[nIdx] = nCost;
				prevIdx[nIdx] = cIdx;

				pq.push({ nCost, nIdx });
			}
		}
	}

	return dist[end];
}

void printPathData(int end) {
	int tmp = end;
	while (tmp != 0) {
		reversePath.push(tmp);
		tmp = prevIdx[tmp];
	}
	cout << reversePath.size() << '\n';

	while (!reversePath.empty()) {
		cout << reversePath.top() << ' ';
		reversePath.pop();
	}
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int s, e, c;
	int start, end;
	cin >> n >> m;

	link.assign(n + 1, {});
	prevIdx.assign(n + 1, 0);

	while (m--) {
		cin >> s >> e >> c;
		link[s].emplace_back(c, e);
	}

	for (int i = 0; i < link.size(); i++) {
		sort(link[i].begin(), link[i].end());
	}
	
	cin >> start >> end;
	cout << dijkstra(start, end) << '\n';

	printPathData(end);
}