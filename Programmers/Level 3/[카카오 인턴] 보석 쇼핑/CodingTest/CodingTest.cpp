#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems) {
	//answer를 최대구간인 { 1,maxSize }로 초기화
	vector<int> answer{ 1, (int)gems.size() };

	//보석의 종류 및 개수를 세는 map
	map<string, int> m;

	//모든 보석을 map에 저장함
	for (const string& str : gems) m[str]++;

	//보석의 종류
	int total = m.size();
	//보석의 길이
	int diff = gems.size();
	//투 포인터 알고리즘을 사용하기위한 변수 ( s; start, e; end )
	int s = 0, e = 0;

	//보석의 종류를 map을 사용하여 구했으니 아래에서 사용하기 위해 map을 초기화
	m.clear();

	while (true)
	{
		//모든 보석이 다 담긴 경우
		if (m.size() == total)
		{
			//diff에 저장되어있던 길이보다 더 짧을 때 값을 바꿔줌
			if (diff > e - s)
			{
				diff = e - s;
				answer[0] = s + 1;
				answer[1] = e;
			}

			//s위치에 있는 보석이 하나뿐일 때, 보석을 맵에서 제거
			if (m[gems[s]] == 1)
				m.erase(gems[s]);
			//s위치에 있는 보석이 2개 이상일 때, 보석의 개수를 감소
			else
				m[gems[s]]--;

			//s위치 이동
			s++;
		}

		//e가 끝에 도달하여 탐색을 종료
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
	auto it = solution({ "DIA", "RUBY", "DIA", "DIA", "EMERALD", "SAPPHIRE", "DIA" });
	cout << it[0] << ' ' << it[1];
}