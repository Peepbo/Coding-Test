#include <iostream>
#include <vector>

using namespace std;

string solution(string s, int n) {
	string answer = "";
	char num;
	bool isSmall = false;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ')
		{
			num = s[i];
		}
		else
		{
			if (s[i] >= 97)isSmall = true;
			else isSmall = false;
			int temp = s[i] + n;
			if (isSmall && temp > 122) temp -= 26;
			else if (!isSmall && temp > 90) temp -= 26;
			num = (char)temp;
		}
		answer += num;
	}
	return answer;
}

int main() {
	solution(3, 5);

	return 0;
}