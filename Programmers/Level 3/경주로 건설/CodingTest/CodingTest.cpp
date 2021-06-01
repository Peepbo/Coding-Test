#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<vector<int>> board) {
    struct Car 
    {
        int x, y, cost, dir; 
    };

    int answer = 999999999, mx[] = { 0,1,0,-1 }, my[] = { 1,0,-1,0 }, boardSize = board.size();
    queue<Car> q;
    Car car{ 0,0,0,-1 };

    q.push(car);
    board[0][0] = 1;

    while (!q.empty())
    {
        Car tempCar = q.front();
        q.pop();

        //목적지에 도착했을 경우
        if (tempCar.x == boardSize - 1 && tempCar.y == boardSize - 1)
        {
            //현재 큐에 저장되어있는 차의 비용이 answer보다 작을 때 answer에 저장한다.
            if (answer > tempCar.cost) answer = tempCar.cost;
            continue;
        }

        //위, 오른쪽, 아래, 왼쪽 순으로 이동 가능성을 살펴 큐에 넣는다.
        for (int i = 0; i < 4; i++)
        {
            int nextX = tempCar.x + mx[i];
            int nextY = tempCar.y + my[i];

            //다음 이동하려는 좌표가 유효하지 않을 때(범위를 벗어남)
            //혹은 해당 좌표가 벽에 의해 가로막혔을 때 continue 처리 한다.
            if (nextX < 0 || nextY < 0 ||
                nextX >= boardSize || nextY >= boardSize ||
                board[nextX][nextY] == 1)continue;

            int nextCost = 0;

            //dir이 -1일 때(최초 시작), 차의 방향이 가려는 방향과 일치할 때 100의 비용을 추가한 후 저장한다.
            if (tempCar.dir == -1 || tempCar.dir == i)
                nextCost = tempCar.cost + 100;
            //방향이 일치하지 않을 때, 코너 비용(500)을 포함한 600의 비용을 추가한 후 저장한다.
            else if (tempCar.dir != i)
                nextCost = tempCar.cost + 600;

            //가려는 곳이 처음 방문했거나, 계산한 코스트가 더 적게 들었을 때
            //현재 위치의 비용을 계산한 코스트로 대체하고, 큐에 추가한다.
            if (board[nextX][nextY] == 0 || board[nextX][nextY] > nextCost)
            {
                board[nextX][nextY] = nextCost;
                Car nextCar{ nextX,nextY,nextCost,i };

                q.push(nextCar);
            }
        }
    }

    return answer;
}

int main()
{
    cout << solution({ { 0,0,0 }, { 0,0,0 }, { 0,0,0 } });
}