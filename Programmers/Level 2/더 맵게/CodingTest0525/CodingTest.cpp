#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0, firstSpicyFood, secondSpicyFood, mixedFood = 0;
    priority_queue<int, vector<int>, greater<int>> scovilleChecker(scoville.begin(), scoville.end());

    while (scovilleChecker.size() > 1 && scovilleChecker.top() < K)
    {
        firstSpicyFood = scovilleChecker.top();
        scovilleChecker.pop();

        secondSpicyFood = scovilleChecker.top();
        scovilleChecker.pop();

        mixedFood = firstSpicyFood + (secondSpicyFood * 2);

        scovilleChecker.push(mixedFood);

        answer++;
    }

    return mixedFood >= K ? answer : -1;
}

int main()
{
    cout << solution({ 1,2,3,9,10,12 }, 7);
}