#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int numbers[31];

//벡터의 원소를 상하 뒤집는 함수
void reverse(vector<vector<int>>& vv)
{
	//begin은 최소 인덱스, end는 최대 인덱스로 초기화한다.
	int begin = 0, end = vv.size() - 1;

	//begin과 end가 같아지거나, begin이 end보다 커질 때 반복문을 나간다.
	while (begin < end)
	{
		swap(vv[begin++], vv[end--]);
	}
}

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0, wSize = board.size(), w, h, pick;
	stack<int> basket;

	reverse(board);

	//각 줄의 인형 위치를 저장하는 작업
	for (int width = 0; width < wSize; width++)
	{
		for (int height = 0; height < wSize; height++)
		{
			//0과 마주치면 더이상 위치를 업데이트 하지 않는다.
			if (board[height][width] == 0)break;

			numbers[width] = height;
		}
	}

	//인형의 위치와 번호를 이용해 바구니에 저장
	for (const int& move : moves)
	{
		//w(width, 가로 위치)
		w = move - 1;

		//만약 더이상 인형을 뽑을 수 없을 때 continue 실행한다.
		if (numbers[w] < 0)continue;

		//h(height, 세로 위치)
		h = numbers[w]--;

		//pick(뽑은 인형, 인형의 번호)
		pick = board[h][w];

		//바구니가 비었거나, 바구니의 맨 위 인형과 뽑은 인형의 숫자가 다를 때
		if (basket.empty() || pick != basket.top())
			//인형을 바구니에 추가한다.
			basket.push(pick);

		//바구니의 맨 위 인형과 뽑은 인형의 숫자가 같을 경우
		else
		{
			//바구니의 맨 위 인형을 제외 시키고
			basket.pop();
			//현재 뽑은 인형 + 제외한 인형, 총 2점을 answer에 더한다.
			answer += 2;
		}
	}

	return answer;
}

int main()
{
	cout << solution({ {0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1} }, { 1,5,3,5,1,2,1,4 });

	return 0;
}