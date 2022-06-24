#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool CheckNumber(int Number)
{
	const string NumberStr = to_string(Number);

	for (int i = 0; i < NumberStr.length() - 2; i++)
	{
		if (NumberStr[i] == '6' && NumberStr[i + 1] == '6' && NumberStr[i + 2] == '6')
		{
			return true;
		}
	}
	return false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int Number = 665;
	int Count = 0;

	while (true)
	{
		if (CheckNumber(Number))
		{
			Count++;

			if (N == Count)
			{
				break;
			}
		}

		Number++;
	}

	cout << Number;
	return 0;
}