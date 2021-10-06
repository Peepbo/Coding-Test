#include <iostream>

using namespace std;

int main(void) {
	int A, I;
	cin >> A >> I;

	if (I == 1)cout << I;
	else cout << A * (I - 1) + 1;

	return 0;
}