#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;

void bubble_sort() {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 1; j < arr.size() - i; j++) {
			if (arr[j] < arr[j - 1])
				swap(arr[j], arr[j - 1]);
		}
	}
}

void print() {
	for (const int& num : arr) {
		cout << num << '\n';
	}
}

int main()
{
	int N, idx = 0;
	cin >> N;
	arr.assign(N, 0);
	while (N--) {
		cin >> arr[idx++];
	}

	bubble_sort();

	print();
	return 0;
}