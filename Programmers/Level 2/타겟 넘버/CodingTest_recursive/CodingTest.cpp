#include <iostream>
#include <string>
#include <vector>

using namespace std;

int collect;
int targetNumber;

void dfs(int index, int sum, const vector<int>& numbers)
{
    if (index == numbers.size())
    {
        if (sum == targetNumber) collect++;

        return;
    }

    dfs(index + 1, sum + numbers[index], numbers);
    dfs(index + 1, sum - numbers[index], numbers);
}

int solution(vector<int> numbers, int target) {
    targetNumber = target;

    dfs(0, 0, numbers);

    return collect;
}

int main()
{
    cout << solution({ 1,1,1,1,1 }, 3);
}