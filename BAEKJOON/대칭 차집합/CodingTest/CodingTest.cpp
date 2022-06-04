#include <iostream>
#include <unordered_set>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unordered_set<int> ElementList;
	int N, M;
	int Input;
	cin >> N >> M;
	while (N--)
	{
		cin >> Input;
		ElementList.insert(Input);
	}
	while (M--)
	{
		cin >> Input;
		const bool bFound{ ElementList.find(Input) != ElementList.end() };

		if (bFound)
		{
			ElementList.erase(Input);
		}
		else
		{
			ElementList.insert(Input);
		}
	}

	cout << ElementList.size();
	return 0;
}