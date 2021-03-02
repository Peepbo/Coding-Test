#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

void calculation(string& num0, const string& num1, const char& sign)
{
	if (sign == '+') num0 = to_string(stoll(num0) + stoll(num1));
	else if (sign == '*') num0 = to_string(stoll(num0) * stoll(num1));
	else if (sign == '-') num0 = to_string(stoll(num0) - stoll(num1));
}

bool isNumber(const char& ch)
{
	return ch == '0' || isdigit(ch) != 0;
}

long long Maximize(string expression, const array<char, 3>& arr)
{
	vector<string> v, v2;
	vector<char> s, s2;

	char sign;

	int start = 0;
	for (int i = 0; i <= expression.size(); i++)
	{
		if (!isNumber(expression[i]))
		{
			v.emplace_back(expression.substr(start, i - start));
			s.emplace_back(expression[i]);
			start = i + 1;
		}
	}

	for (int k = 0; k < 3; k++)
	{
		sign = arr[k];
		int idx = 0;
		int combo = 1;

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == sign)
			{
				calculation(v[idx], v[i + 1], sign);
				combo++;

				if (i + 1 == s.size()) v2.emplace_back(v[idx]);
			}
			else
			{
				if (idx != i)
				{
					v2.emplace_back(v[idx]);
					s2.emplace_back(s[i]);

					idx += combo;
					combo = 1;
				}
				else
				{
					v2.emplace_back(v[idx]);
					s2.emplace_back(s[i]);

					idx++;
				}
			}
		}

		if (s2.empty())break;
		else
		{
			v = v2;
			s = s2;
			v2.clear();
			s2.clear();
		}
	}

	return abs(stoll(v.front()));
}

long long solution(string expression) {
	long long answer = 0;

	answer = Maximize(expression, { '*','+','-' });
	answer = max(answer, Maximize(expression, { '*','-','+' }));
	answer = max(answer, Maximize(expression, { '-','*','+' }));
	answer = max(answer, Maximize(expression, { '+','*','-' }));
	answer = max(answer, Maximize(expression, { '+','-','*' }));
	answer = max(answer, Maximize(expression, { '-','+','*' }));

	return answer;
}

int main()
{
	cout << solution("10-20*30*50-20*8");
	return 0;
}