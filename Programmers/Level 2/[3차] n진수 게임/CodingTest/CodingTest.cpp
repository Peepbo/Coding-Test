#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

stack<char> GetNumber(int num, int n)
{
    stack<char> s;
    while (num > 0)
    {
        if (num % n >= 10) 
            s.push(num % n - 10 + 'A');
        else 
            s.push(num % n + '0');

        num /= n;
    }
    return s;
}

string solution(int n, int t, int m, int p) {
    string answer = "";

    if (p == 1) answer += '0';

    int order = 2;
    int num = 1;

    stack<char> st;

    while (answer.size() < t)
    {
        st = GetNumber(num, n);

        while (!st.empty() && answer.size() != t)
        {
            if (p == order) answer += st.top();

            st.pop();

            order++;
            if (order > m)order = 1;
        }

        num++;
    }

    return answer;
}

int main()
{
    cout << solution(16, 16, 2, 1);

	return 0;
}