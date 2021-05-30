#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;

    if (n > s) answer.emplace_back(-1);
    else if (n == s) answer.assign(1, n);
    else
    {
        while (n > 0)
        {
            answer.emplace_back(s / n);
            s -= answer.back();

            n--;
        }
    }

    return answer;
}

int main()
{
    auto vec = solution(5,9);

    for (auto& it : vec)
        cout << it << endl;
}