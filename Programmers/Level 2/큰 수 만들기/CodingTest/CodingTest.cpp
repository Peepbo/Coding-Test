#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int len = number.size();

    int pivot = -1;
    for (int i = 0; i < len - k; i++)
    {
        char max = 0;

        for (int j = pivot + 1; j <= k + i; j++)
        {
            if (max < number[j])
            {
                max = number[j];
                pivot = j;
            }
        }
        answer += max;
    }

    return answer;
}

int main()
{
    cout << solution("4177252841", 4);

	return 0;
}