#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    bool Big = true;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            Big = true;
            continue;
        }

        if (Big)
        {
            s[i] = toupper(s[i]);
            Big = false;
        }
        else s[i] = tolower(s[i]);
    }

    return s;
}

int main()
{
    cout << solution("3people unFollowed me");

	return 0;
}