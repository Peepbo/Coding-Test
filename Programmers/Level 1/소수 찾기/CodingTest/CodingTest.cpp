#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;
	vector<int> numbers(n + 1);
	for (int i = 2; i <= n; i++)
	{
		numbers[i] = i;
	}

	for (int i = 2; i <= n; i++)
	{
		if (numbers[i] == 0)continue;

		for (int j = i * 2; j <= n; j += i)
		{
			numbers[j] = 0;
		}
	}
	for (int i = 2; i <= n; i++)
	{
		if (numbers[i] != 0)answer++;
	}
	return answer;
}

int main()
{


	return 0;
}