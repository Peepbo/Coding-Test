#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = 0;
    int size = s.size();

    string str = s;

    stack<char> st;

    map<char, char> reverse;
    map<char, char> direction;

    reverse['('] = ')'; reverse[')'] = '(';
    reverse['{'] = '}'; reverse['}'] = '{';
    reverse['['] = ']'; reverse[']'] = '[';

    direction['('] = direction['{'] = direction['['] = 'L';
    direction[')'] = direction['}'] = direction[']'] = 'R';

    for (int i = 0; i < size; i++)
    {
        rotate(str.begin(), str.begin() + 1, str.end());

        st = {};
        bool isWrong = false;

        for (const char& ch : str)
        {
            if (direction[ch] == 'L')
            {
                st.push(ch);
            }
            else //'R'
            {
                if (st.empty() || reverse[st.top()] != ch)
                {
                    isWrong = true;
                    break;
                }

                else st.pop();
            }
        }

        if (st.empty() && !isWrong) answer++;
    }

    return answer;
}

int main()
{
    cout << solution("}}}");
}