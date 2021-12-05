#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

#define INF 999999999
vector<tuple<int, int, int>> graph;

void bellmanFord(const int& N) {
	vector<long long> bDist(N + 1, INF);
	bDist[1] = 0;
	int a, b, dist;

	for (int i = 0; i < N - 1; i++) {
		for (const auto& tp : graph) {
			a = get<0>(tp);
			b = get<1>(tp);
			dist = get<2>(tp);

			if (bDist[a] != INF && bDist[b] > bDist[a] + dist) {
				bDist[b] = bDist[a] + dist;
			}
		}
	}

	for (const auto& tp : graph) {
		a = get<0>(tp);
		b = get<1>(tp);
		dist = get<2>(tp);

		if (bDist[a] != INF && bDist[b] > bDist[a] + dist) {
			cout << -1;
			return;
		}
	}

	for (int i = 2; i <= N; i++) {
		cout << (bDist[i] != INF ? bDist[i] : -1) << '\n';
	}
}

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M, A, B, C;
	cin >> N >> M;

	while (M--) {
		cin >> A >> B >> C;
		graph.emplace_back(make_tuple(A, B, C));
	}

	bellmanFord(N);

	return 0;
}