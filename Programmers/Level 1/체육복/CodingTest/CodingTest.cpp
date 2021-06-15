#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;

	bool check = false;
	//도난 당하지 않은 학생들
	answer += n - lost.size();

	//도난 당했지만 여벌을 가져온 학생
	for (int i = 0; i < reserve.size();)
	{
		for (int j = 0; j < lost.size();)
		{
			if (reserve[i] == lost[j])
			{
				answer++;
				lost.erase(lost.begin() + j);
				reserve.erase(reserve.begin() + i);
				check = true; // i 증가 안해도됨
				break;
			}
			else j++;
		}
		if (!check)i++;
		else check = false;
	}
	if (!lost.empty() && !reserve.empty())
	{
		for (int i = 0; i < reserve.size();)
		{
			for (int j = 0; j < lost.size();)
			{
				if (reserve[i] + 1 == lost[j] || reserve[i] - 1 == lost[j])
				{
					answer++;
					lost.erase(lost.begin() + j);
					reserve.erase(reserve.begin() + i);
					check = true; // i 증가 안해도됨
					break;
				}
				else j++;
			}
			if (!check)i++;
			else check = false;
		}
	}
	return answer;
}

int main()
{

}