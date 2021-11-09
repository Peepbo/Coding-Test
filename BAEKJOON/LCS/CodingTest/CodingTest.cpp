#include <iostream>

using namespace std;

int bp[1001][1001];

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int aMax, bMax;
	string A, B;

	cin >> A >> B;
	aMax = A.size();
	bMax = B.size();
	A = " " + A;
	B = " " + B;
	for (int i = 1; i <= bMax; i++) {
		for (int j = 1; j <= aMax; j++) {
			if (B[i] == A[j]) {
				bp[i][j] = bp[i - 1][j - 1] + 1;
			}
			else {
				bp[i][j] = max(bp[i - 1][j], bp[i][j - 1]);
			}
		}
	}

	cout << bp[bMax][aMax];
	return 0;
}