#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> v;

void hanoi(int n, int start, int mid, int end)
{
    if (n == 1)
    {
        v.emplace_back(vector<int>{ start, end });
        return;
    }

    hanoi(n - 1, start, end, mid);
    v.emplace_back(vector<int>{ start,end });
    hanoi(n - 1, mid, start, end);
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    hanoi(n, 1, 2, 3);
    
    answer.assign(v.begin(), v.end());
    return answer;
}

int main()
{
    solution(3);

	return 0;
}