#include <iostream>
#include <string>
#include <vector>
#include <map>

#define x first
#define y second
#define intPair pair<int,int>

using namespace std;

map<char, int> mp;
map<intPair, string> dirMap;

const int limit = 10;

bool limitChecker(const int& value, const int& move)
{
    return (value + move > limit || value + move < 0);
}

int solution(string dirs) {
    int answer = 0;
    intPair pos(5, 5), startPt, endPt;
    int len = dirs.size();
    char order, reOrder;
    int move;

    mp['U'] = 1; mp['D'] = -1;
    mp['R'] = 1; mp['L'] = -1;

    for (int i = 0; i < len; i++)
    {
        order = dirs[i];
        move = mp[order];

        startPt = endPt = { pos.x,pos.y };

        if (order == 'U' || order == 'D')
        {
            if (limitChecker(pos.y, move))continue;

            endPt.y += move;

            if (order == 'U')reOrder = 'D';
            else reOrder = 'U';

            if (dirMap[startPt] == "" && dirMap[endPt] == "")
            {
                dirMap[startPt] += order;
                dirMap[endPt] += reOrder;
                answer++;
            }
            else if (dirMap[startPt].find(order) == -1 &&
                     dirMap[endPt].find(reOrder) == -1)
            {
                dirMap[startPt] += order;
                dirMap[endPt] += reOrder;
                answer++;
            }

            pos.y += move;
        }
        else
        {
            if (limitChecker(pos.x, move))continue;

            endPt.x += move;

            if (order == 'R')reOrder = 'L';
            else reOrder = 'R';

            if (dirMap[startPt] == "" && dirMap[endPt] == "")
            {
                dirMap[startPt] += order;
                dirMap[endPt] += reOrder;
                answer++;
            }
            else if (dirMap[startPt].find(order) == -1 &&
                     dirMap[endPt].find(reOrder) == -1)
            {
                dirMap[startPt] += order;
                dirMap[endPt] += reOrder;
                answer++;
            }

            pos.x += move;
        }
    }

    return answer;
}

int main()
{
    cout << solution("UDU");

	return 0;
}