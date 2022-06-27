#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string S;
	int q;
	char Alphabet;
	int Start, End;
	cin >> S >> q;

	const int Length = S.length();
	map<char, vector<int>> SumMap;

	while (q--)
	{
		cin >> Alphabet >> Start >> End;

		if (SumMap.find(Alphabet) == SumMap.end())
		{
			SumMap[Alphabet].assign(Length, 0);

			for (int i = 0; i < Length; i++)
			{
				if (S[i] == Alphabet)
				{
					SumMap[Alphabet][i]++;
				}

				if (i > 0)
				{
					SumMap[Alphabet][i] += SumMap[Alphabet][i - 1];
				}
			}
		}

		const int Sub{ Start == 0 ? 0 : SumMap[Alphabet][Start - 1] };
		cout << SumMap[Alphabet][End] - Sub << '\n';
	}

	return 0;
}