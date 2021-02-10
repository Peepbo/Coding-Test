#include <iostream>
#include <string>
#include <stack>

using namespace std;

string solution(int n) {
	string answer = "";
	stack<char> stk;
	char ch, topNum;

	while (n > 0)
	{
		if (n % 3 == 0)
		{
			ch = 4 + '0';
			n = n / 3 - 1;
		}
		else
		{
			ch = n % 3 + '0';
			n /= 3;
		}
		stk.push(ch);
	}

	while (!stk.empty())
	{
		topNum = stk.top();
		stk.pop();
		answer += topNum;
	}

	return answer;
}

int main()
{
	cout << solution(3);

	return 0;
}