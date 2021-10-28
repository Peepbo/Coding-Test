#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

#define INF 999999999

vector<vector<int>> graph;
vector<vector<int>> dist;

vector<int> Dijkstra(const int& start) {
	vector<int> sDistance(graph.size(), INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	pq.push({ 0,start }); // cost, idx
	sDistance[start] = 0;

	while (!pq.empty()) {
		int cost = pq.top().first;
		int now = pq.top().second;
		pq.pop();

		for (const int& next : graph[now]) {
			if (sDistance[next] > cost + dist[now][next]) {
				sDistance[next] = cost + dist[now][next];
				pq.push({ sDistance[next], next });
			}
		}
	}

	return sDistance;
}

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T, n, m, t, s, g, h, a, b, d, x;
	cin >> T;

	while (T--) {
		cin >> n >> m >> t;
		cin >> s >> g >> h;

		graph.assign(n + 1, vector<int>());
		dist.assign(n + 1, vector<int>(n + 1, INF));
		set<int> printer;

		while (m--) {
			cin >> a >> b >> d;
			graph[a].emplace_back(b);
			graph[b].emplace_back(a);
			dist[a][b] = dist[b][a] = d;
		}

		while (t--) {
			cin >> x;
			auto sDist = Dijkstra(s);
			auto hDist = Dijkstra(h);
			auto gDist = Dijkstra(g);

			if (sDist[x] == sDist[h] + dist[h][g] + gDist[x] ||
				sDist[x] == sDist[g] + dist[g][h] + hDist[x]) {
				printer.insert(x);
			}
		}

		for (const int& num : printer) {
			cout << num << ' ';
		}
		cout << '\n';
	}

	return 0;
}