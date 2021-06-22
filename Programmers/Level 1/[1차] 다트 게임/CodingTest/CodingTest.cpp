#include <string>
#include <math.h>
using namespace std;

int solution(string dartResult) {
	int answer = 0;
	int score[3];
	int order = 0;
	for (int i = 0; i < dartResult.length(); i++)
	{
		if (dartResult[i] > 47 && dartResult[i] < 58)
		{
			if (i > 0) order++;
			if (dartResult[i + 1] > 47 && dartResult[i + 1] < 58)
			{
				score[order] = (dartResult[i] - '0') * 10 + (int(dartResult[i + 1] - '0'));
				i++;
			}
			else
			{
				score[order] = (int(dartResult[i] - '0'));
			}
		}
		else if (dartResult[i] == 'D') score[order] = pow(score[order], 2);
		else if (dartResult[i] == 'T') score[order] = pow(score[order], 3);
		else if (dartResult[i] == '#') score[order] *= -1;
		else if (dartResult[i] == '*')
		{
			if (order > 0)
			{
				score[order] *= 2;
				score[order - 1] *= 2;
			}
			else score[order] *= 2;
		}
	}
	for (int i = 0; i < 3; i++)
	{
		answer += score[i];
	}
	return answer;
}

int main()
{
}