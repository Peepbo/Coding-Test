#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 999999999

struct Node {
	int weight, index;
};

struct compare {
	bool operator()(const Node& left, const Node& right) const{
		if (left.weight != right.weight)
			return left.weight > right.weight;
		else
			return left.index > right.index;
	}
};

int main(void) {
	int V, E, S, a, b, w;
	cin >> V >> E >> S;

	vector<vector<Node>> list(V + 1);
	vector<int> dist(V + 1, INF);

	dist[S] = 0;
	
	for (int i = 0; i < E; i++) {
		cin >> a >> b >> w;

		list[a].emplace_back(Node{ w, b });
	}

	//dijkstra
	priority_queue<Node, vector<Node>, compare> pq;
	pq.push({ 0, S });
	vector<bool> visited(V);
	int weight, idx, linkIdx, linkWeight;

	while (!pq.empty()) {
		weight = pq.top().weight;
		idx = pq.top().index;

		pq.pop();

		for (const Node& node : list[idx]) {
			linkIdx = node.index;
			linkWeight = node.weight;

			if (visited[linkIdx])continue;

			if (dist[linkIdx] > weight + linkWeight) {
				dist[linkIdx] = weight + linkWeight;

				pq.push({ dist[linkIdx], linkIdx });
			}
		}

		visited[idx] = true;
	}

	//print
	for (int i = 1; i <= V; i++) {
		if (dist[i] != INF) 
			cout << dist[i] << '\n';
		else
			cout << "INF" << '\n';
	}

	return 0;
}