#include <iostream>

using namespace std;

int Parent[201];

int GetParent(int a) {
	if (a == Parent[a]) return a;
	return Parent[a] = GetParent(Parent[a]);
}

bool IsSameParent(int a, int b) {
	a = GetParent(a);
	b = GetParent(b);
	return a == b;
}

void UnionParent(int a, int b) {
	a = GetParent(a);
	b = GetParent(b);
	a < b ? Parent[b] = a : Parent[a] = b;
}

bool Kruskal() {
	int N, M, city, nextCity;
	bool isLink;

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		Parent[i] = i;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> isLink;

			if (isLink && !IsSameParent(i, j)) {
				UnionParent(i, j);
			}
		}
	}

	cin >> city;
	for (int i = 2; i <= M; i++) {
		cin >> nextCity;
		if (!IsSameParent(city, nextCity)) {
			return false;
		}
	}
	return true;
}

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	Kruskal() ? cout << "YES" : cout << "NO";
	return 0;
}