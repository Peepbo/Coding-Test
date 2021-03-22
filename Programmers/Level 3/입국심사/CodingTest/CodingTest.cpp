#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
	long long answer = 0;
	sort(times.begin(), times.end());

	long long left = times.front();
	long long right = (long long)times.back() * n;

	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long cnt = 0;

		for (int i = 0; i < times.size(); i++)
			cnt += mid / times[i];

		if (cnt >= n)
		{
			answer = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}

	return answer;
}

int main()
{
	cout << solution(6, { 7,10 });

	return 0;
}