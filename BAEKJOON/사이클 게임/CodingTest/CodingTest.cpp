#include <iostream>

using namespace std;

int Parent[500'001];

int GetParent(int a) {
	if (a == Parent[a])return a;
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

int Kruskal() {
	int n, m, cnt = 0;
	int m1, m2;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		Parent[i] = i;
	}

	for (int i = 1; i <= m; i++) {
		cin >> m1 >> m2;

		if (IsSameParent(m1, m2)) {
			cnt = i;
			break;
		}
		else {
			UnionParent(m1, m2);
		}
	}

	return cnt;
}

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cout << Kruskal();
	return 0;
}