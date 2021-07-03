#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
	bool answer = true;
	for (int i = 0; i < s.size(); i++)
	{
		if ((int)s[i] > 57 || (int)s[0] == 32) answer = false;
	}
	return answer;
}

int main()
{
}