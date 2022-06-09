#include <iostream>
#include <unordered_set>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unordered_set<string> NumberSet;
	int N, M, Count = 0;
	string Input;
	cin >> N >> M;
	while (N--)
	{
		cin >> Input;
		NumberSet.insert(Input);
	}
	while (M--)
	{
		cin >> Input;

		if (NumberSet.find(Input) != NumberSet.end())
		{
			Count++;
		}
	}

	cout << Count;
	return 0;
}