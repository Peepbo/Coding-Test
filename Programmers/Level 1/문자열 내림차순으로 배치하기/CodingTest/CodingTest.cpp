#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	string answer = "";

	while (answer.size() != s.size()) // answer과 s의 크기가 같을 때 종료
	{
		int big = 0;
		for (int i = 1; i < s.size(); i++)
		{
			if ((int)s[big] < (int)s[i])
			{
				big = i;
			}
		}// 비교가 끝나면
		answer += s[big]; // 해당 값을 넣고
		s[big] = '@'; // 문자중 가장 낮은 10진수 값을 넣어줌
	}
	return answer;
}

int main()
{
}