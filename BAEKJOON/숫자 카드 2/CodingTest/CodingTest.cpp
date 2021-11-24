#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	cin.sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	unordered_map<int, int> uMap;
	long long input;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> input;
		uMap[input]++;
	}

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> input;
		cout << uMap[input] << ' ';
	}
	return 0;
}