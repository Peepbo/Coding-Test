#include <iostream>
#include <vector>
#include <string>

using namespace std;

int MOD = 20170805;

int pairSum(pair<int, int> pr)
{
    return pr.first + pr.second;
}

int solution(int m, int n, vector<vector<int>> city_map) {
    pair<int, int> nowPr, leftPr, topPr;
    pair<int, int> arr[501][501];
    int topType, leftType;

    arr[0][1] = { 0,1 };

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (city_map[i - 1][j - 1] == 1) continue;

            leftPr = arr[i][j - 1];
            topPr = arr[i - 1][j];

            nowPr = { 0,0 };

            topType = city_map[i - 2][j - 1];
            leftType = city_map[i - 1][j - 2];

            if (i - 2 < 0 || topType == 2) nowPr.second = topPr.second;

            else nowPr.second = pairSum(topPr) % MOD;

            if (j - 2 < 0 || leftType == 2) nowPr.first = leftPr.first;

            else nowPr.first = pairSum(leftPr) % MOD;

            arr[i][j] = nowPr;
        }
    }

    return pairSum(arr[m][n]) % MOD;
}

int main()
{
    solution(3, 6, { {0,2,0,0,0,2},{0,0,2,0,1,0},{1,0,0,2,2,0} });
}