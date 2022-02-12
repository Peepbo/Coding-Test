#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TimeData {
	int start, end;
};

bool compare(TimeData a, TimeData b) {
	if (a.end == b.end) {
		return a.start < b.start;
	}
	return a.end < b.end;
}

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, s, e, last, cnt = 0;
	cin >> N;
	vector<TimeData> vec(N);
	for (int i = 0; i < N; i++) {
		cin >> s >> e;
		vec[i] = { s,e };
	}
	sort(vec.begin(), vec.end(), compare);

	last = vec[0].end;
	cnt = 1;

	for (int i = 1; i < N; i++) {
		if (last <= vec[i].start) {
			last = vec[i].end;
			cnt++;
		}
	}

	cout << cnt;
	return 0;
}