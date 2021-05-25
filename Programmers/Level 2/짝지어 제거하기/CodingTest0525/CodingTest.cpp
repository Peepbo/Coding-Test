#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s)
{
    if (s.size() % 2 != 0)return 0;

    int answer = 1;
    stack<char> checker;

    for (const char& ch : s)
    {
        if (!checker.empty() && checker.top() == ch)
            checker.pop();
        else 
            checker.push(ch);
    }

    return checker.empty()? 1 : 0;
}

int main()
{
    //cout << solution("baabaa");
    cout << solution("cdcd");
}