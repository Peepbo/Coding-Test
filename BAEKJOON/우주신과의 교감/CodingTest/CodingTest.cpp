#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <tuple>

using namespace std;

int n;

pair<float, float> God[1'001];
int parent[1'001];
vector<tuple<double, int, int>> vec;

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

void init() {
	double dist;
	int x, y;
	int m, m1, m2;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> x >> y;
		God[i] = { x,y };
		parent[i] = i;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			dist = sqrt(pow(God[i].first - God[j].first, 2) + pow(God[i].second - God[j].second, 2));
			vec.emplace_back(dist, i, j);
		}
	}
	sort(vec.begin(), vec.end());

	for (int i = 0; i < m; i++) {
		cin >> m1 >> m2;
		unionParent(m1, m2);
	}
}

void kruskal() {
	double answer = 0;
	double dist;
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

	printf("%.2f", answer);
}

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	init();

	kruskal();
	return 0;
}