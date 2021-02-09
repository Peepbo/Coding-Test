#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 0;

    while (true)
    {
        if (a.empty())return answer;

        answer += a.back() * b.back();

        a.pop_back();
        b.pop_back();
    }

    return answer;
}

void main()
{
    cout << solution({ -1,0,1 }, { 1,0,-1 });
}