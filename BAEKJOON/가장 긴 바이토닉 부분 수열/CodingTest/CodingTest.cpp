#include <iostream>

using namespace std;

int A[1001], L[1001], R[1001], S[1001];

int main(void) {
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, idx = 0, answer = 0;
	cin >> N;
	while (N--) {
		cin >> A[++idx];
	}

	// solve L, L[1] = 0
	for (int i = 2; i <= idx; i++) {
		for (int j = 1; j < i; j++) {
			if (A[i] > A[j] && L[i] < L[j] + 1) {
				L[i] = L[j] + 1;
			}
		}
	}
	// solve R, R[idx] = 0;
	for (int i = idx; i >= 1; i--) {
		for (int j = i + 1; j <= idx; j++) {
			if (A[i] > A[j] && R[i] < R[j] + 1) {
				R[i] = R[j] + 1;
			}
		}

		S[i] = max(S[i], L[i] + 1 + R[i]);
		answer = max(answer, S[i]);
	}
	
	cout << answer;
	return 0;
}