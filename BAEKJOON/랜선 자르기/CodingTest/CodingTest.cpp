#include <iostream>

using namespace std;

long long arr[10'001], N, K, maximum;

void binary_search(long long left, long long right) {
	if (left > right)return;

	const long long center = (left + right) / 2;
	if (maximum > center)return;
	
	int count = 0;
	for (int i = 1; i <= K; i++) {
		count += (arr[i] / center);
	}
	
	if (count >= N) {
		maximum = max(maximum, center);
		binary_search(center + 1, right);
	}
	else if (count < N) {
		binary_search(left, center - 1);
	}
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long maxValue = 0;
	cin >> K >> N;

	for (int i = 1; i <= K; i++) {
		cin >> arr[i];

		maxValue = max(maxValue, arr[i]);
	}

	binary_search(1, maxValue);

	cout << maximum;
	return 0;
}