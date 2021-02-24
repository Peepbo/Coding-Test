#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int num = n;
	int count = 0, cpCnt = 0;

	while (n > 0)
	{
		int t = n % 2;
		n /= 2;

		if (t == 1)count++;
	}

	while (count != cpCnt)
	{
		num++;
		cpCnt = 0;

		int cpNum = num;
		while (cpNum > 0)
		{
			int t = cpNum % 2;
			cpNum /= 2;
			if (t == 1)cpCnt++;
		}
	}

	return num;
}

int main()
{
	solution(15);

	return 0;
}