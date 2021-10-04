#include <iostream>

using namespace std;

int main(void) {
	int N, num;
	
	cin >> N;

	while (N > 1) {
		num = 2;
		while (N % num != 0) {
			num++;
		}

		cout << num << '\n';
		N /= num;
	}

	return 0;
}