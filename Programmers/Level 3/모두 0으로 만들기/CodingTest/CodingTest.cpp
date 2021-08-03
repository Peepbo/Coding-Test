#include <iostream>

#include <string>
#include <vector>

using namespace std;

long long Answer = 0;

vector<vector<int>> Graph;
vector<long long> Sum;

void DFS(int now, int parent) {
	for (auto& it : Graph[now]) {
		if (it != parent)
			DFS(it, now);
	}

	Sum[parent] += Sum[now];
	Answer += abs(Sum[now]);
}

long long solution(vector<int> a, vector<vector<int>> edges) {
	int weightCheck = 0;

	Sum.assign(a.size(), 0LL);

	for (int i = 0; i < a.size(); i++) {
		Sum[i] = a[i];
		weightCheck += a[i];
	}

	if (weightCheck != 0)return -1;

	Graph.assign(a.size(), {});

	for (const auto& edge : edges) {
		Graph[edge[0]].push_back(edge[1]);
		Graph[edge[1]].push_back(edge[0]);
	}

	DFS(0, 0);

	return Answer;
}

int main() {
	cout << solution({ -5,0,2,1,2 }, { {0,1},{3,4},{2,3},{0,3} });

	return 0;
}