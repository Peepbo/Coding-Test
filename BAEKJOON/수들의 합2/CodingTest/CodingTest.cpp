#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
	string answer = "";

	string pad[4] = { {1,2,3}
					,{4,5,6},
					 {7,8,9},
					 {10,0,20} };

	int arrL[2] = { 3,0 }; //상하,좌우
	int arrR[2] = { 3,2 }; //상하,좌우

	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] % 3 == 1)
		{
			answer += 'L';
			arrL[0] = numbers[i] / 3;
			arrL[1] = 0;
			continue;
		}
		if (numbers[i] % 3 == 0 && numbers[i] != 0)
		{
			answer += 'R';
			arrR[0] = (numbers[i] / 3 - 1);
			arrR[1] = 2;
			continue;
		}

		int goal[2] = { 0,0 };
		for (int k = 0; k < 4; k++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (numbers[i] == pad[k][j])
				{
					goal[0] = k; // 상하
					goal[1] = j; // 좌우
					break;
				}
			}
		}
		int moveL = abs(goal[0] - arrL[0]) + abs(goal[1] - arrL[1]);
		int moveR = abs(goal[0] - arrR[0]) + abs(goal[1] - arrR[1]);

		if (moveL < moveR)
		{
			answer += 'L';
			arrL[0] = goal[0];
			arrL[1] = goal[1];
		}
		else if (moveL > moveR)
		{
			answer += 'R';
			arrR[0] = goal[0];
			arrR[1] = goal[1];
		}
		else if (moveL == moveR)
		{
			if (hand == "right")
			{
				answer += 'R';
				arrR[0] = goal[0];
				arrR[1] = goal[1];
			}
			else
			{
				answer += 'L';
				arrL[0] = goal[0];
				arrL[1] = goal[1];
			}
		}
	}
	return answer;
}

int main()
{
}