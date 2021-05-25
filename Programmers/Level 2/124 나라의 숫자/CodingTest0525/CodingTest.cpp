#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    char number;

    while (n > 0)
    {
        number = n % 3 + '0';
        if (number == '0')
        {
            number = '4';
            n--;
        }

        answer = number + answer;

        n /= 3;
    }

    return answer;
}

int main()
{
    cout << solution(20) << endl;
}