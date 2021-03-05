#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 1;

	while (true)
	{
		if (a % 2 == 0 && b == a - 1) break;
		else if (b % 2 == 0 && a == b - 1) break;

		if (a % 2 == 0) a /= 2;
		else a = a / 2 + 1;

		if (b % 2 == 0) b /= 2;
		else b = b / 2 + 1;

		answer++;
	}

    return answer;
}

int main()
{
    cout << solution(8, 4, 7);

	return 0;
}