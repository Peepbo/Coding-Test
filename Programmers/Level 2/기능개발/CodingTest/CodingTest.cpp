#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	vector<int> days;

	int len = progresses.size();
	int persent, remains;

	for (int i = 0; i < len; i++)
	{
		persent = 100 - progresses[i];
		remains = persent / speeds[i];

		if (persent % speeds[i] == 0)
			days.emplace_back(remains);
		else
			days.emplace_back(remains + 1);
	}

	int now = days[0];
	answer.emplace_back(1);

	for (int i = 1; i < len; i++)
	{
		if (now < days[i])
		{
			answer.emplace_back(1);
			now = days[i];
		}
		else answer.back()++;
	}

	return answer;
}

int main()
{
	vector<int> v = solution({ 95,90,99,99,80,99 }, { 1,1,1,1,1,1 });
	//for (int i = 0; i < v.size(); i++) cout << v[i] << '\n';

	return 0;
}