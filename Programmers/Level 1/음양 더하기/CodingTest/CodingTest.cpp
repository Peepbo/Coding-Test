#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0, idx = 0;

    for (const int& num : absolutes)
    {
        answer += (signs[idx++] ? num : -num);
    }

    return answer;
}

int main()
{
    cout << solution({ 4,7,12 }, { true,false,true });
}