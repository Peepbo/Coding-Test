#include <iostream>
#include <string>
#include <vector>

using namespace std;
#define SIZE 3150

int arr[SIZE];
int solution(vector<int> nums) {
    int answer = 0;

    arr[0] = arr[1] = 0;
    for (int i = 2; i < SIZE; i++) arr[i] = i;

    for (int i = 2; i < SIZE; i++)
    {
        if (arr[i] == 0)continue;

        for (int j = i * 2; j < SIZE; j += i)
        {
            arr[j] = 0;
        }
    }

    int len = nums.size();
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            for (int k = j + 1; k < len; k++)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (arr[sum] != 0) answer++;
            }
        }
    }

    return answer;
}

int main()
{
    cout << solution({1,2,7,6,4});

	return 0;
}