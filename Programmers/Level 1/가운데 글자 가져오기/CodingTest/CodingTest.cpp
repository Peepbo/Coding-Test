#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	string answer = "";
	int order = 0;
	if (s.size() % 2 != 0) // 홀수 일 때
	{
		order = s.size() / 2;
		answer += s[order];
	}
	else // 짝수 일 때
	{
		order = s.size() / 2 - 1;
		answer += s[order];
		answer += s[order + 1];
	}
	return answer;
}

int main()
{
}