#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long left, long long right) {
    vector<int> answer(right - left + 1);
    int idx = 0;

    while (left <= right) {
        answer[idx] = max(left % n, left / n) + 1;

        idx++;
        left++;
    }

    return answer;
}

int main()
{
    solution(4, 7, 14);

	return 0;
}