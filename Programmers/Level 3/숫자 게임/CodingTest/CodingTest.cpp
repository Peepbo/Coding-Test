#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0, left = 0, right = B.size() - 1;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for (int i = A.size() - 1; i >= 0; i--)
    {
        if (A[i] < B[right])
        {
            answer++;

            right--;
        }

        else
        {
            if (A[i] < B[left]) answer++;
            
            left++;
        }
    }

    return answer;
}

int main()
{
    cout << solution({ 4,1,5,7 }, { 6,1,4,5 });
}