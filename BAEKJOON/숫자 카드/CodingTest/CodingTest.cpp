#include <iostream>
#include <unordered_set>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unordered_set<int> NumberSet;
	int N, M, Input;
	cin >> N;
	while (N--)
	{
		cin >> Input;
		NumberSet.insert(Input);
	}

	cin >> M;
	while (M--)
	{
		cin >> Input;

		cout << (NumberSet.find(Input) != NumberSet.end() ? 1 : 0) << ' ';
	}

	return 0;
}