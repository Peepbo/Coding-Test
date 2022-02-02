#include <iostream>
#include <vector>

using namespace std;

int N;
bool isDecimal[4'000'001];
vector<int> decimalNum;

void Eratos() {
	fill(isDecimal, isDecimal + 4'000'000, true);

	const int halfN = N / 2;

	for (int i = 2; i <= halfN; i++) {
		if (!isDecimal[i]) continue;

		for (int j = i + i; j <= N; j += i) {
			isDecimal[j] = false;
		}
	}
}

void Init() {
	for (int i = 2; i <= N; i++) {
		if (isDecimal[i]) {
			decimalNum.emplace_back(i);
		}
	}
}

int Solve() {
	const int rimit = decimalNum.size();
	int count = 0;
	int s = 0, e = 0;
	int sum = decimalNum.empty() ? 0 : decimalNum.front();

	if (rimit == 0)return rimit;

	while (s <= e) {
		if (sum == N) {
			count++;
		}

		if (sum < N) {
			e++;
			if (e == rimit)break;
			sum += decimalNum[e];
		}
		else {
			sum -= decimalNum[s];
			s++;
		}
	}

	return count;
}

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;

	Eratos();
	Init();

	cout << Solve();
	return 0;
}