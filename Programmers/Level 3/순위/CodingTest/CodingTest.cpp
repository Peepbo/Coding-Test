#include <iostream>

#include <string>
#include <vector>

using namespace std;

bool matrix[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    for (const vector<int>& result : results) {
        matrix[result[0]][result[1]] = true;
    }

    for (int z = 1; z <= n; z++) {
        for (int y = 1; y <= n; y++) {
            for (int x = 1; x <= n; x++) {
                if (matrix[y][z] && matrix[z][x])
                    matrix[y][x] = true;
            }
        }
    }

    for (int y = 1; y <= n; y++) {
        int count = 0;
        for (int x = 1; x <= n; x++) {
            if (matrix[y][x] || matrix[x][y])
                count++;
        }

        if (count == n - 1)
            answer++;
    }

    return answer;
}

int main()
{
    cout << solution(5, { {4,3},{4,2},{3,2},{1,2},{2,5} });

	return 0;
}