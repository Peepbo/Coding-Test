#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;

void merge(int a, int eA, int b, int eB) {
	vector<int> temp;
	const int tempA = a;

	while (a <= eA || b <= eB) {
		if (a > eA || (b <= eB && arr[a] > arr[b])) {
			temp.emplace_back(arr[b++]);
		}
		else if (b > eB || (a <= eA && arr[a] < arr[b])) {
			temp.emplace_back(arr[a++]);
		}
	}

	for (int i = 0; i <= eB - tempA; i++) {
		arr[tempA + i] = temp[i];
	}
}

void merge_sort(int s, int e) {
	const int sub = e - s;
	if (sub == 0)return;

	const int half = sub / 2;
	int A = s, endA = s + half, B = s + half + 1, endB = e;

	merge_sort(A, endA);
	merge_sort(B, endB);
	merge(A, endA, B, endB);
}

void print() {
	for (const int& num : arr) {
		cout << num << '\n';
	}
}

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, idx = 0;
	cin >> N;
	arr.assign(N, 0);
	while (N--) {
		cin >> arr[idx++];
	}

	merge_sort(0, arr.size() - 1);

	print();
	return 0;
}