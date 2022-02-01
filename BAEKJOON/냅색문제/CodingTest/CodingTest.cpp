#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;
int arr[31];
vector<int> a, b;

void recur(int idx, int end, int used, vector<int>& vecRef) {
	if (idx > end) {
		vecRef.emplace_back(used);
		return;
	}

	recur(idx + 1, end, used, vecRef);
	if (used + arr[idx] <= C) {
		recur(idx + 1, end, used + arr[idx], vecRef);
	}
}

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int result = 0;
	cin >> N >> C;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	recur(1, N / 2, 0, a);
	recur(N / 2 + 1, N, 0, b);

	sort(b.begin(), b.end());

	for (int used : a) {
		auto iter = upper_bound(b.begin(), b.end(), C - used);
		if (iter != b.begin()) {
			result += iter - b.begin();
		}
	}

	cout << result;
	return 0;
}