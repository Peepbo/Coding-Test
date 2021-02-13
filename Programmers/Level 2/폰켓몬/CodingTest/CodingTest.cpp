#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> nums)
{
	int answer = 0;
	int len = nums.size();
	int halfLen = len / 2;

	sort(nums.begin(), nums.end());
	unique(nums.begin(), nums.end());

	int before = nums.front();
	for (int i = 1; i < len; i++)
	{
		if (before < nums[i])
		{
			if (i == halfLen)
			{
				answer = halfLen;
				break;
			}
		}

		else
		{
			answer = i;
			break;
		}

		before = nums[i];
	}
	return answer;
}

int main()
{
	cout << solution({ 3,3,3,2,2,2 });

	return 0;
}