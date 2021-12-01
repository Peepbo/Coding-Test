#include <iostream>

using namespace std;

int arr[10001];

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, input;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> input;
		arr[input]++;
	}

	for (int i = 0; i < 10001; i++) {
		if (arr[i] == 0)continue;

		for (int j = 0; j < arr[i]; j++) {
			cout << i << '\n';
		}
	}
	return 0;
}