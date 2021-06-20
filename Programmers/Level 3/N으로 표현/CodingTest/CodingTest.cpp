#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class info
{
public:
    int cnt, sum;
public:
    void copy(int& _cnt, int& _sum)
    {
        _cnt = cnt;
        _sum = sum;
    }
};

int solution(int N, int number) {
    int answer = 9, temp, cnt, sum;

    queue<info> q;
    q.push({ 0, 0 });

    while (!q.empty())
    {
        info _info = q.front();
        _info.copy(cnt, sum);

        q.pop();

        if (cnt > 8)continue;
        if (sum == number)
        {
            answer = min(answer, cnt);
            continue;
        }

        temp = 0;

        for (int i = 1; (i + cnt) < 9; i++)
        {
            temp = temp * 10 + N;

            q.push({ cnt + i,sum + temp });
            q.push({ cnt + i,sum - temp });
            q.push({ cnt + i,sum * temp });
            q.push({ cnt + i,sum / temp });
        }
    }

    return answer == 9? -1 : answer;
}

int main()
{
    cout << solution(5, 12);
}