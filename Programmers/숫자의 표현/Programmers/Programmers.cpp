#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 1;
    int Order = 1;

    while (Order < n)
    {
        int num = Order;
        int last = num;

        while (num < n)
        {
            last++;

            num += last;

            if (num == n) answer++;
        }
        
        Order++;
    }

    return answer;
}

int main()
{
    cout << solution(15);
}