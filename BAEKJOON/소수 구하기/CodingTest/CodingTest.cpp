#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	int N, M, halfM;
	cin >> N >> M;

	halfM = M / 2;

	vector<bool> isDecimal(M + 1, true);
	isDecimal[0] = isDecimal[1] = false;

	for (int i = 2; i <= halfM; i++) {
		if (isDecimal[i] == false)continue;

		for (int j = i * 2; j <= M; j += i) {
			isDecimal[j] = false;
		}
	}

	for (int i = N; i <= M; i++) {
		if (isDecimal[i]) {
			cout << i << '\n';
		}
	}

	return 0;
}