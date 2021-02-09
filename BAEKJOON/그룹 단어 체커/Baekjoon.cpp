#include <iostream>
#include <vector>

using namespace std;

bool HaveCheck(vector<char> &check, char ch)
{
	for (int i = 0; i < check.size(); i++)
	{
		if (ch == check[i]) return true;
	}

	check.push_back(ch);
	return false;
}

int main()
{
	int N, count = 0;
	cin >> N;

	string input = "";
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		
		vector<char> check;

		check.push_back(input.front());
		char now = input.front();

		bool getPt = true;
		for (int j = 1; j < input.length(); j++)
		{
			if (now == input[j])continue;

			else
			{
				now = input[j];

				if (HaveCheck(check, input[j]))
				{
					getPt = false;
					break;
				}
			}
		}
		if (getPt) count++;
	}

	cout << count;

	return 0;
}