#include <iostream>

using namespace std;

int N, M;

void solve(int idx, string str, int last) {
	if (str.size() == M) {
		for (const char& ch : str) {
			cout << ch << ' ';
		}
		cout << '\n';

		return;
	}

	for (int i = 1; i <= N; i++) {
		if (last <= i) {
			solve(idx + 1, str + char(i + '0'), i);
		}
	}
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	solve(0, "", 0);

	return 0;
}