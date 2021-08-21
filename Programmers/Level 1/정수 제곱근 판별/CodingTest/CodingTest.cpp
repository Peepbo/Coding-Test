#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(long long n) {
	long long answer = 0;

	double cul = (double)n / 2;
	long long sub = 1;
	while (cul - sub > 0)
	{
		cul -= sub;
		sub++;
	}
	if (cul * 2 == double(sub))answer = (sub + 1) * (sub + 1);
	else answer = -1;

	return answer;
}

int main()
{

}