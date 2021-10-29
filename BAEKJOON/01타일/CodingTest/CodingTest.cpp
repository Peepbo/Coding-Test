#include <iostream>

using namespace std;

int arr[2];

int main(void) {
	int N, temp;
	cin >> N;

	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i <= N; i++) {
		temp = arr[0] + arr[1];
		arr[0] = arr[1];
		arr[1] = temp % 15746;
	}

	cout << arr[1];
	return 0;
}