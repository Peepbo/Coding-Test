#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int rtnCount(int cur, int speed)
{
    int ctn = 0;
    while (cur < 100)
    {
        cur += speed;
        ctn++;
    }

    return ctn;
}

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> cal;

    if (progresses.size() == 1)
    {
        answer.push_back(rtnCount(progresses.front(), speeds.front()));
    }
    
    else
    {
        for (int i = 0; i < progresses.size(); i++)
        {
            int curNum = progresses[i];

            int result = rtnCount(curNum, speeds[i]);

            cal.push_back(result);
        }

        int count = 1;
        int num = cal[0];
        for (int i = 1; i < cal.size(); i++)
        {
            cout << cal[i] << '\n';

            if (num > cal[i])count++;
            else
            {
                answer.push_back(count);

                count = 1;
                num = cal[i];
            }
        }

        answer.push_back(count);
    }

    return answer;
}

int main()
{
    vector<int> v1 = solution({ 99,1,99,1 }, { 1,1,1,1 });

    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << ", ";
    }
}