#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <tuple>

using namespace std;

int n;

pair<float, float> Star[101];
int parent[101];
vector<tuple<float, int, int>> vec;

void init() {
	float x, y, dist;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y;
		Star[i] = { x,y };
		parent[i] = i;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			dist = sqrt(pow((Star[i].first - Star[j].first), 2) + pow((Star[i].second - Star[j].second), 2));
			vec.emplace_back(dist, i, j);
		}
	}
	sort(vec.begin(), vec.end());
}

int findParent(int a) {
	if (a == parent[a])return a;

	return parent[a] = findParent(parent[a]);
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

float kruskal() {
	float answer = 0;

	float dist;
	int a, b;

	for (const auto& tp : vec) {
		dist = get<0>(tp);
		a = get<1>(tp);
		b = get<2>(tp);

		if (sameParent(a, b) == false) {
			unionParent(a, b);
			answer += dist;
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