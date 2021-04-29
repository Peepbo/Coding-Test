#include <iostream>
#include <vector>

using namespace std;

int arr[101][101];

#define y first
#define x second
#define intPair pair<int,int>

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    int order, minNum, save, next, verticalCount, horizontalCount, myCount;
    intPair pairs[] = { {0,1},{1,0},{0,-1},{-1,0},{0,0} };
    intPair move, now;
    vector<int> answer;
    bool isVertical;

    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= columns; j++)
        {
            arr[i][j] = (i - 1) * columns + j;
        }
    }


    for (const auto& vec : queries)
    {
        order = 0;

        move = pairs[order];
        now = { vec[0],vec[1] };

        minNum = arr[now.y][now.x];
        save = arr[now.y][now.x];
        next = arr[now.y + move.y][now.x + move.x];

        isVertical = false;
        verticalCount = vec[2] - vec[0];
        horizontalCount = vec[3] - vec[1];

        myCount = 0;

        while (save != next)
        {
            if (order == 4)
            {
                answer.emplace_back(minNum);
                break;
            }

            arr[now.y + move.y][now.x + move.x] = save;
            minNum = min(minNum, save);

            save = next;

            myCount++;

            now.x += move.x;
            now.y += move.y;

            if (isVertical && myCount == verticalCount)
            {
                isVertical = false;
                myCount = 0;

                move = pairs[++order];
            }

            else if (!isVertical && myCount == horizontalCount)
            {
                isVertical = true;
                myCount = 0;

                move = pairs[++order];
            }

            next = arr[now.y + move.y][now.x + move.x];
        }
    }

    return answer;
}

int main()
{
    //auto vec = solution(6, 6, { {2,2,5,4},{3,3,6,6},{5,1,6,3} });
    auto vec = solution(3, 3, { {1,1,2,2},{1,2,2,3},{2,1,3,2},{2,2,3,3} });

    for (const int& num : vec)
    {
        cout << num << ' ';
    }
}