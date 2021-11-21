#include <iostream>
#include <vector>

using namespace std;

#define INF 2000000000
vector<vector<pair<int,int>>> graph;
vector<vector<int>> fDist;
int minCycle = INF;

void FloydWarshall(const int& V) {
	for (int k = 1; k <= V; k++) {
		for (int s = 1; s <= V; s++) {
			for (int e = 1; e <= V; e++) {
				if (fDist[s][k] != INF && fDist[k][e] != INF) {
					if (fDist[s][e] > fDist[s][k] + fDist[k][e]) {
						fDist[s][e] = fDist[s][k] + fDist[k][e];
					}
				}
			}
		}
	}
}

int main(void) {
	int V, E, a, b, c;
	cin >> V >> E;
	
	graph.assign(V + 1, {});
	fDist.assign(V + 1, vector<int>(V + 1, INF));
	
	while (E--) {
		cin >> a >> b >> c;
		graph[a].emplace_back(b, c);
		fDist[a][b] = c;
	}

	FloydWarshall(V);

	// i ~> k ~> i
	for (int i = 1; i <= V; i++) {
		for (int k = 1; k <= V; k++) {
			if (i == k)continue;

			if (fDist[i][k] != INF && fDist[k][i] != INF) {
				minCycle = min(minCycle, fDist[i][k] + fDist[k][i]);
			}
		}
	}
	
	cout << (minCycle != INF ? minCycle : -1);
	return 0;
}