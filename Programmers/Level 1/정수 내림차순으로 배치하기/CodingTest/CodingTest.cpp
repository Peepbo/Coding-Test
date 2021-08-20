#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
	long long answer = 0;
	vector<long long> vc;

	long long num = n;
	while (num > 0)
	{
		vc.push_back(num % 10);
		num /= 10;
	}
	for (long long i = 0; i < vc.size() - 1; i++)
	{
		for (long long j = 1; j < vc.size() - i; j++)
		{
			if (vc[j - 1] < vc[j])
				swap(vc[j - 1], vc[j]);
		}
	}
	long long order = 10;
	bool zeroIn = false;
	for (long long i = vc.size() - 1; i >= 0; i--)
	{
		if (answer == 0 && !zeroIn)
		{
			answer += vc[i];
			zeroIn = true;
		}
		else
		{
			answer += vc[i] * order;
			order *= 10;
		}
	}
	return answer;
}

int main()
{

}