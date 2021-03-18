#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> money) {
    vector<long long> nums(n + 1);

    sort(money.begin(), money.end());
    
    for (int i = 0; i <= n; i++)
    {
        if (i % money.front() == 0) nums[i] = 1;
    }

    for (int i = 1; i < money.size(); i++)
    {
        for (int j = money[i]; j <= n; j++)
        {
            nums[j] += nums[j - money[i]];
            nums[j] %= 1000000007;
        }
    }

    return nums[n];
}

int main()
{
    cout << solution(5, { 1,2,5 });

    return 0;
}