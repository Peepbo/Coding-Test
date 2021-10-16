#include <iostream>

using namespace std;

int main(void) {
	long long A, B, C;

	while (true) {
		cin >> A >> B >> C;
		if (A == 0 && B == 0 && C == 0) break;
		
		if (C < A)swap(C, A);
		if (C < B)swap(C, B);
		
		if (A * A + B * B == C * C) {
			cout << "right" << '\n';
		}
		else {
			cout << "wrong" << '\n';
		}
	}

	return 0;
}