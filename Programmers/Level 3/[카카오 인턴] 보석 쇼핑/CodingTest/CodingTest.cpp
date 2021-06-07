#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems) {
	vector<int> answer{ 1, (int)gems.size() };

	map<string, int> m;

	for (const string& str : gems)
		m[str]++;

	int total = m.size();
	int diff = gems.size();
	int s = 0, e = 0;

	m.clear();

	while (true)
	{
		//모든 보석이 다 담긴 경우
		if (m.size() == total)
		{
			if (diff > e - s)
			{
				diff = e - s;
				answer[0] = s + 1;
				answer[1] = e;
			}

			if (m[gems[s]] == 1)
			{
				m.erase(gems[s]);
				s++;
			}

			else if (m[gems[s]] - 1 > 0)
			{
				m[gems[s]]--;
				s++;
			}
		}

		//끝까지 탐색하면 종료
		else if (e == gems.size())break;
		//보석 종류를 다 포함하지 못하면 끝 인덱스를 이동
		else 
		{
			m[gems[e]]++;
			e++;
		}
	}

	return answer;
}

int main()
{

}