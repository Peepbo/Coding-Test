#include <string>
#include <vector>

using namespace std;

bool Select[20];
int targetNum, ways, len;

void DFS(vector<int> v, int idx, int cnt, int max)
{
    if (cnt == max)
    {
        int sum = 0;
        int num;
        for (int i = 0; i < len; i++)
        {
            Select[i] ? num = -1 * v[i] : num = v[i];
            sum += num;
        }

        if (sum == targetNum)
        {
            ways++;
        }

        return;
    }

    for (int i = idx; i < len; i++)
    {
        if (Select[i])continue;
        Select[i] = true;
        DFS(v, i, cnt + 1, max);
        Select[i] = false;
    }
}

int solution(vector<int> numbers, int target) {

    targetNum = target;
    len = numbers.size();

    for (int i = 0; i <= len; i++)
    {
        DFS(numbers, 0, 0, i);
    }

    return ways;
}

int main()
{
    solution({ 1,1,1,1,1 }, 3);

	return 0;
}