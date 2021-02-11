#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

void Length2Binary(string& s)
{
	int len = s.length();
	s = "";

	stack<char> stk;
	while (len > 0)
	{
		stk.push((len % 2) + '0');
		len /= 2;
	}

	while (stk.empty() == false)
	{
		s += stk.top();
		stk.pop();
	}
}

vector<int> solution(string s) {
	vector<int> answer;

	int count = 0, delCount = 0;

	while (s != "1")
	{
		count++;

		for (int i = 0; i < s.size();)
		{
			if (s[i] == '0')
			{
				s.erase(s.begin() + i);
				delCount++;
			}
			else i++;
		}

		Length2Binary(s);
	}

	answer.assign({ count,delCount });

	return answer;
}

int main()
{
	vector<int> v = solution("110010101001");

	for (int i = 0; i < 2; i++)cout << v[i] << '\n';

	return 0;
}