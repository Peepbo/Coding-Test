#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

#define INF 999999999

struct Node {
	int value, dist;
};

struct compare {
	bool operator() (Node a, Node b) {
		if (a.dist != b.dist) return a.dist > b.dist;
		return a.value > b.dist;
	}
};

int main(void) {
	int N, E, best = INF;
	cin >> N >> E;
	vector<vector<Node>> graph(N + 1);

	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		graph[a].emplace_back(Node{b, c});
		graph[b].emplace_back(Node{a, c});
	}

	int A, B;
	cin >> A >> B;

	const int arr[2]{ A,B };
	vector<int> tDist[2] { vector<int>(N + 1, INF), vector<int>(N + 1, INF) };
	priority_queue<Node, vector<Node>, compare> pq;
	set<int> visited;

	for (int i = 0; i < 2; i++) {
		visited.clear();

		tDist[i][arr[i]] = 0;

		pq.push({ arr[i],0 });
		while (!pq.empty()) {
			Node now = pq.top();
			pq.pop();

			for (const auto& next : graph[now.value]) {
				if (visited.find(next.value) == visited.end()) {
					if (tDist[i][next.value] > now.dist + next.dist) {
						tDist[i][next.value] = now.dist + next.dist;
						pq.push(Node{ next.value,tDist[i][next.value] });
					}
				}
			}
			visited.insert(now.value);
		}
	}

	//1 - A - B - N
	if (tDist[0][1] < INF && tDist[0][B] < INF && tDist[1][N] < INF) {
		best = min(best, tDist[0][1] + tDist[0][B] + tDist[1][N]);
	}

	//1 - B - A - N
	if (tDist[1][1] < INF && tDist[1][A] < INF && tDist[0][N] < INF) {
		best = min(best, tDist[1][1] + tDist[1][A] + tDist[0][N]);
	}

	if (best == INF)cout << -1;
	else cout << best;
	
	return 0;
}