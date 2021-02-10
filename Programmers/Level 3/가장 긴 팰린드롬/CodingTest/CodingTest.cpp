#include <iostream>
#include <string>
using namespace std;

int checkLength(string str, int& best, bool isOdd)
{
	int start = 1;
	if (isOdd) start = 2;

	for (int i = start; i < str.size(); i++)
	{
		int leftN = i - start;
		int rightN = i;

		int palindrome = 0;
		if (isOdd) palindrome = 1; 

		while (str[leftN] == str[rightN])
		{
			palindrome += 2;

			leftN--;
			rightN++;

			if (leftN < 0 || rightN == str.size())
			{
				if (best < palindrome) best = palindrome;
				break;
			}

			if (str[leftN] != str[rightN])
			{
				if (best < palindrome) best = palindrome;
				break;
			}
		}
	}
	
	return best;
}

int solution(string s)
{
	int answer = 0;

	checkLength(s, answer, true);
	checkLength(s, answer, false);

	if (answer == 0)return 1;

	return answer;
}

int main()
{
	cout << solution("abacde");

	return 0;
}