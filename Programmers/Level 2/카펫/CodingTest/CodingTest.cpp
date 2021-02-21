#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int yW = yellow, yH = 1;
    int value;

    stack<int> sk;
    for (int i = 2; i <= yellow / 2; i++)
    {
        if (yellow % i == 0)
        {
            sk.push(i);
        }
    }
    sk.push(yellow);
    
    while ((value = 2 * (yW + yH + 2)) != brown)
    {
        yW = sk.top();
        sk.pop();
        yH = yellow / yW;
    }

    return { yW + 2,yH + 2 };
}

int main()
{
    auto output = solution(24, 24);

    cout << '[';
    for (const auto& it : output)
    {
        cout << it << ',';
    }
    cout << ']';

	return 0;
}