#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	int* order = new int[N + 1];
	int* number = new int[N + 1];//개수
	double* rate = new double[N + 1];//실패율
	for (int i = 1; i < N + 1; i++)
	{
		order[i] = i;
		number[i] = 0;
	}

	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 0; j < stages.size(); j++)
		{
			if (i == stages[j])number[i]++;

		}
	}

	int maxNum = stages.size();
	for (int i = 1; i < N + 1; i++)
	{
		if (maxNum <= 0)rate[i] = 0;
		else
		{
			rate[i] = (double)number[i] / maxNum;
			maxNum -= number[i];
		}
	}

	for (int i = 1; i < N; i++)
	{
		for (int j = 2; j <= (N + 1) - i; j++)
		{
			if (rate[j] > rate[j - 1])
			{
				swap(rate[j], rate[j - 1]);
				swap(order[j], order[j - 1]);
			}
		}
	}
	for (int i = 1; i < N + 1; i++) // 1,2,3,4,5
	{
		answer.push_back(order[i]);
	}
	return answer;
}

int main()
{

}