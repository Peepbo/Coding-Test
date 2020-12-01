#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(int n) {
    int answer = 0;

    int before = 0;

    //0, 1, 1, 2, 3, 5

    for (int i = 0; i <= n; i++)
    {
        if (i == 1)
        {
            answer = i;
            before = 0;
        }

        else
        {
            int save = answer;

            answer += before;
            before = save;

            answer %= 1234567;
        }
    }
    return answer;
}

void main()
{
    solution(30);
}