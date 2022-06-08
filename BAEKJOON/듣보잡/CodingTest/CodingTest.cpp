#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unordered_map<string, int> UnknownList;
	vector<string> OutputList;
	int N, M;
	string Input;

	cin >> N >> M;
	while (N--)
	{
		cin >> Input;
		UnknownList[Input]++;
	}
	while (M--)
	{
		cin >> Input;
		UnknownList[Input]++;
	}

	for (const auto& PairElement : UnknownList)
	{
		if (PairElement.second == 2)
		{
			OutputList.emplace_back(PairElement.first);
		}
	}

	sort(OutputList.begin(), OutputList.end());
	cout << OutputList.size() << '\n';
	for (const string& Name : OutputList)
	{
		cout << Name << '\n';
	}
	return 0;
}