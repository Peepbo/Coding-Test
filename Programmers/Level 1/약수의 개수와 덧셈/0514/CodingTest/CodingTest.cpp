#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0, count;

    for (int num = left; num <= right; num++)
    {
        count = 1;

        if (num > 1)
        {
            for (int i = 1; i <= num / 2; i++)
            {
                if (num % i == 0)count++;
            }
        }

        if (count % 2 == 0) answer += num;
        else answer -= num;
    }

    return answer;
}

int main()
{
    cout << solution(24, 27);
}