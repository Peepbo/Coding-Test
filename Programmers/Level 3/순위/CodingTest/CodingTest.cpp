#include <iostream>
#include <vector>

using namespace std;

bool matrix[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0, win, loss;

    for (const vector<int>& result : results) {
        win = result[0];
        loss = result[1];

        matrix[win][loss] = true;
    }

    for (int l = 1; l <= n; l++) {
        for (int w = 1; w <= n; w++) {
            for (int ll = 1; ll <= n; ll++) {
                if (matrix[w][l] && matrix[l][ll])
                    matrix[w][ll] = true;
            }
        }
    }

    for (int a = 1; a <= n; a++) {
        int count = 0;
        for (int b = 1; b <= n; b++) {
            if (matrix[a][b] || matrix[b][a])
                count++;
        }

        if (count == n - 1)
            answer++;
    }

    return answer;
}

int main() {

	return 0;
}