#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0, scovilleOfFirst, scovilleOfSecond, scovilleOfMixed = 0;
    priority_queue<int, vector<int>, greater<int>> scovilleChecker(scoville.begin(), scoville.end());

    while (scovilleChecker.size() > 1 && scovilleChecker.top() < K)
    {
        scovilleOfFirst = scovilleChecker.top();
        scovilleChecker.pop();

        scovilleOfSecond = scovilleChecker.top();
        scovilleChecker.pop();

        scovilleOfMixed = scovilleOfFirst + (scovilleOfSecond * 2);

        scovilleChecker.push(scovilleOfMixed);

        answer++;
    }

    return scovilleOfMixed >= K ? answer : -1;
}

int main()
{
    cout << solution({ 1,2,3,9,10,12 }, 7);
}