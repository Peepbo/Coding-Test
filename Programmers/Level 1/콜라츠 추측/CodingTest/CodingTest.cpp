#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int num) {
	int count = 0;
	long long number = num;
	while (number != 1)
	{
		if (number % 2 == 0)number /= 2;
		else number = (number * 3) + 1;
		count++;
		if (count >= 500)
		{
			count = -1;
			break;
		}
	}
	return count;
}

int main() {
	return 0;
}