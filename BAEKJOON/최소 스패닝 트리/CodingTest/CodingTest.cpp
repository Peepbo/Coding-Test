#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

vector<int> parent;
vector<tuple<int, int, int>> vec;

void init() {
	int V, E, A, B, C;
	cin >> V >> E;

	parent = vector<int>(V + 1);
	vec = vector<tuple<int, int, int>>(E);

	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < E; i++) {
		cin >> A >> B >> C;
		vec[i] = make_tuple(C, A, B);
	}

	sort(vec.begin(), vec.end());
}

int findParent(int idx) {
	if (idx == parent[idx])return idx;
	return parent[idx] = findParent(parent[idx]);
}

void unionParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);

	if (a < b)parent[b] = a;
	else parent[a] = b;
}

bool sameParent(int a, int b) {
	a = findParent(a);
	b = findParent(b);

	if (a == b)return true;
	return false;
}

long long kruskal() {
	long long answer = 0;
	int V1, V2, weight;

	for (const auto& tp : vec) {
		weight = get<0>(tp);
		V1 = get<1>(tp);
		V2 = get<2>(tp);

		if (sameParent(V1, V2) == false) {
			unionParent(V1, V2);
			answer += weight;
		}
	}

	return answer;
}

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	init();

	cout << kruskal();
	return 0;
}