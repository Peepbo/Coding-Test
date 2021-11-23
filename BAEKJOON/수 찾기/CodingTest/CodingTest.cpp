#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> arr;

bool binary_search(pair<int, int> range, const long long& num) {
	if (range.first > range.second)return false;

	const int pivot = (range.first + range.second) / 2;
	if (arr[pivot] > num) {
		return binary_search({ range.first, pivot - 1 }, num);
	}
	else if (arr[pivot] < num) {
		return binary_search({ pivot + 1, range.second }, num);
	}
	else { // arr[pivot] == num
		return true;
	}
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	long long find;
	cin >> N;

	arr.assign(N, 0);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> find;
		cout << binary_search({ 0,arr.size() - 1 }, find) << '\n';
	}
	return 0;
}