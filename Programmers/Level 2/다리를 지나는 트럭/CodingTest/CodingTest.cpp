#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	queue<int> q;

	int order = 0, nWeight = 0, time = 0;
	int remain = truck_weights.size();
	while (remain > 0)
	{
		time++;

		if (q.size() == bridge_length)
		{
			if (q.front() != 0)
			{
				nWeight -= q.front();
				remain--;
			}
			
			q.pop();
		}

		if (order != truck_weights.size() && nWeight + truck_weights[order] <= weight)
		{
			nWeight += truck_weights[order];
			q.push(truck_weights[order]);

			order++;
		}

		else q.push(0);
	}

	return time;
}

int main()
{
	cout << solution(2, 10, { 7,4,5,6 });

	return 0;
}