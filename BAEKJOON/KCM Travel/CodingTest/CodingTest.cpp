#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

#define INF 999999999
#define llii tuple<long long,int,int>

vector<vector<tuple<int, int, int>>> graph;
int dp[101][10001];

void Dijkstra(const int& N, const int& M) {
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			dp[i][j] = INF;
		}
	}


	priority_queue<llii, vector<llii>, greater<llii>> pq; // 시간, 위치, 비용
	pq.push(make_tuple(0, 1, M));
	dp[1][M] = 0;

	int now, cost, next, nCost, time, nTime, mMin = INF;

	while (!pq.empty()) {
		time = get<0>(pq.top());
		now = get<1>(pq.top());
		cost = get<2>(pq.top());
		pq.pop();

		if (now == N) {
			mMin = min(mMin, time);
			continue;
		}
		
		for (const auto& tp : graph[now]) {
			nTime = get<0>(tp);
			next = get<1>(tp);
			nCost = get<2>(tp);

			if (cost - nCost >= 0) {
				if (dp[next][cost - nCost] <= time + nTime)continue;

				dp[next][cost - nCost] = time + nTime;
				pq.push(make_tuple(time + nTime, next, cost - nCost));
			}
		}
	}

	if (mMin == INF) {
		cout << "Poor KCM" << '\n';
	}
	else {
		cout << mMin << '\n';
	}
}

int main(void) {
	int T, N, M, K, u, v, c, d;
	cin >> T;
	
	while (T--) {
		cin >> N >> M >> K;

		graph.assign(N + 1, {});
		while (K--) {
			cin >> u >> v >> c >> d; // 출발, 도착, 비용, 시간
			graph[u].emplace_back(make_tuple(d, v, c)); // 시간, 도착, 비용
		}

		Dijkstra(N, M);
	}

	return 0;
}