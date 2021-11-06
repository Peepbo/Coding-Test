#include <iostream>

using namespace std;

#define MOD 1'000'000'000

int save;
int last[10];
int now[10];

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, count;
	long long newCount;
	cin >> N;

	for (int i = 1; i <= 9; i++) {
		last[i] = 1;
	}
	save = 1;
	count = 9;

	//save : s[start-2][1]
	//last : s[start-1][all]
	//now  : s[start][all]
	while (--N) { //if n > 1
		newCount = 0;
		// i==1
		now[1] = (save + last[2]) % MOD;
		newCount += now[1];
		// 1<i<9
		for (int i = 2; i < 9; i++) {
			now[i] = (last[i - 1] + last[i + 1]) % MOD;
			newCount += now[i];
		}
		// i==9
		now[9] = last[8] % MOD;
		newCount += now[9];

		save = last[1];
		swap(last, now); // last = now, now = last (다음에 덮어 쓸 공간)

		count = newCount % MOD;
	}

	cout << count;
	return 0;
}