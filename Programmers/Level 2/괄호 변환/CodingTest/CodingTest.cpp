#include <iostream>
#include <string>
#include <vector>

using namespace std;

string Recursion(string str)
{
    if (str == "")return str;

    int open = 0, close = 0;
    
    string u, v;

    bool uWrite = true, Collect = true;

    int len = str.size();
    for (int i = 0; i < len; i++)
    {
        if (uWrite)
        {
            u += str[i];

            if (str[i] == '(')open++;
            else close++;

            if (open < close) Collect = false;

            else if (open == close) uWrite = false;
        }

        else v += str[i];
    }

    if (Collect)
    {
        return u + Recursion(v);
    }
    else
    {
        string temp;
        temp = '(' + Recursion(v) + ')';

        for (int i = 1; i < u.size() - 1; i++)
        {
            if (u[i] == '(') temp += ')';
            else temp += '(';
        }

        return temp;
    }
}

string solution(string p) {
    return Recursion(p);
}

int main()
{
    cout << solution("(()())()");

	return 0;
}