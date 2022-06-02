#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool compare(const string& S1, const string& S2)
{
	if (S1.length() != S2.length())
	{
		return S1.length() < S2.length();
	}
	return S1 < S2;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	string Input;
	cin >> N;
	vector<string> Arr;
	set<string> WordSet;
	while (N--)
	{
		cin >> Input;
		if (WordSet.find(Input) == WordSet.end())
		{
			WordSet.insert(Input);
			Arr.emplace_back(Input);
		}
	}
	sort(Arr.begin(), Arr.end(), compare);
	for (const string& S : Arr)
	{
		cout << S << '\n';
	}
	return 0;
}