#include <iostream>

using namespace std;

int solution(string input)
{
	string check[8] = { "dz=","lj","nj","c=","s=","z=","c-","d-" };

	int count = 0;
	int order = 0;

	for (int i = 0; i < 8; i++)
	{
		int idx = input.find(check[i]);
		while (idx != -1)
		{
			input.replace(idx, check[i].length(), "*");
			count++;

			idx = input.find(check[i]);
		}
		order++;
	}

	for (int i = 0; i < input.length(); i++)
		if (input[i] != '*')count++;

	return count;
}

int main()
{
	string input;
	cin >> input;
	cout << solution(input);

	return 0;
}