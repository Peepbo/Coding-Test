#include <iostream>

using namespace std;

int Parent[1'000'001];

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

void Kruskal() {
	int n, m, a, b;
	bool isIntersection;

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		Parent[i] = i;
	}

	while (m--) {
		cin >> isIntersection >> a >> b;

		if (isIntersection) {
			IsSameParent(a, b) ? cout << "YES\n" : cout << "NO\n";
		}
		else {
			if (IsSameParent(a, b) == false) {
				UnionParent(a, b);
			}
		}
	}
}

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	Kruskal();

	return 0;
}