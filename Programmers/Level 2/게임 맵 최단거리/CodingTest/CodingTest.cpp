#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int dist[101][101], dh[] = { -1,0,1,0 }, dw[] = { 0,1,0,-1 };

int BFS(const vector<vector<int>>& maps, int maxH, int maxW)
{
    dist[0][0] = 1;
    queue<pair<int, int>> q;
    q.push({ 0,0 });

    while (!q.empty())
    {
        int h = q.front().first; // 나의 h 위치
        int w = q.front().second; // 나의 w 위치
        q.pop();

        if (h == maxH && w == maxW) // 목적지에 도착함
        {
            return dist[h][w];
        }

        for (int i = 0; i < 4; i++) // 4방향을 모두 검사함
        {
            //1. 다음 좌표
            int nextH = h + dh[i], nextW = w + dw[i];

            //2. 경로 검사
            if (nextH < 0 || nextW < 0 || nextH > maxH || nextW > maxW)continue; // 0보다 작거나 max보다 클 때 continue
            if (maps[nextH][nextW] == 0 || dist[nextH][nextW] != 0)continue; // 가려는 곳이 벽이거나, 이미 도달한 곳이면 continue

            //3. 거리 계산
            dist[nextH][nextW] = dist[h][w] + 1; // 다음 위치 거리는 걸어왔던 거리에서 1을 더한 값 

            //4. 큐에 푸시
            q.push({ nextH,nextW }); // 다음 경로가 유효하면 큐에 넣음
        }
    }
    return -1;
}

int solution(vector<vector<int>> maps)
{
    return BFS(maps, maps.size() - 1, maps[0].size() - 1);
}

int main()
{
    cout << solution({ {1, 0, 1, 1, 1},{1, 0, 1, 0, 1},{1, 0, 1, 1, 1},{1, 1, 1, 0, 1},{0, 0, 0, 0, 1 } });

    return 0;
}