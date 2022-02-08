#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int N;
vector<pair<int, pair<int, int>>> Dist;
tuple<int, int, int> Planet[100'001];
int Parent[100'001];

void init() {
	int x, y, z;
	int a, b;
	int d1, d2, distance, idx = 0;
	cin >> N;

	map<pair<int, int>, int> DistMap;
	vector<pair<int, int>> arr[3];
	arr[0] = arr[1] = arr[2] = vector<pair<int, int>>(N + 1);

	for (int i = 1; i <= N; i++) {
		cin >> x >> y >> z;
		arr[0][i] = { x, i };
		arr[1][i] = { y, i };
		arr[2][i] = { z, i };
	}
	
	sort(arr[0].begin() + 1, arr[0].end());
	sort(arr[1].begin() + 1, arr[1].end());
	sort(arr[2].begin() + 1, arr[2].end());

	for (int i = 0; i < 3; i++) {
		for (int j = 2; j <= N; j++) {
			a = arr[i][j - 1].second;
			b = arr[i][j].second;

			d1 = arr[i][j - 1].first;
			d2 = arr[i][j].first;
			distance = abs(d1 - d2);

			if (DistMap.find({ a,b }) == DistMap.end() ||
				DistMap[{a, b}] > distance) {
				DistMap[{a, b}] = distance;
			}
		}
	}

	Dist = vector<pair<int, pair<int, int>>>(DistMap.size());
	for (const auto& it : DistMap) {
		distance = it.second;
		a = it.first.first;
		b = it.first.second;

		Dist[idx++] = { distance,{a,b} };
	}
	sort(Dist.begin(), Dist.end());
}

int GetParent(int idx) {
	if (Parent[idx] == idx)return idx;
	return Parent[idx] = GetParent(Parent[idx]);
}

void UnionParent(int a, int b) {
	a = GetParent(a);
	b = GetParent(b);

	if (a < b)Parent[b] = a;
	else Parent[a] = b;
}

bool SameParent(int a, int b) {
	a = GetParent(a);
	b = GetParent(b);

	return a == b;
}

int kruskal() {
	int answer = 0;
	int distance, a, b;
	for (int i = 1; i <= N; i++) {
		Parent[i] = i;
	}

	for (const auto& it : Dist) {
		distance = it.first;
		a = it.second.first;
		b = it.second.second;

		if (SameParent(a, b) == false) {
			answer += distance;
			UnionParent(a, b);
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