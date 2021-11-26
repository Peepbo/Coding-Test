#include <iostream>

using namespace std;

int N, M, arr[1'000'001];

int binary_search(long long s, long long e) {
	long long sum = 0, output = 0, pivot = s;

	while (s >= e) {
		pivot = (s + e) / 2;

		sum = 0;
		for (int i = 1; i <= N; i++) {
			if (arr[i] > pivot) {
				sum += arr[i] - pivot;
			}
		}

		if (sum < M) {
			s = pivot - 1;
		}
		else {
			output = max(output, pivot);
			e = pivot + 1;
		}
	}

	return output;
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int maximum = 0;

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		maximum = max(maximum, arr[i]);
	}

	cout << binary_search(maximum, 0);

	return 0;
}