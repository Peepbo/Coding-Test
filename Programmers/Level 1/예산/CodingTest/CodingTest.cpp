#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> d, int budget) {
	int answer = 0;
	//정렬
	for (int i = 0; i < d.size() - 1; i++)
	{
		for (int j = 1; j < d.size() - i; j++)
		{
			if (d[j - 1] > d[j]) swap(d[j - 1], d[j]);
		}
	}
	//예산 계산
	for (int i = 0; i < d.size(); i++)
	{
		if (budget < d[i])break;
		else
		{
			budget -= d[i];
			answer++;
		}
	}
	return answer;
}

int main()
{

}