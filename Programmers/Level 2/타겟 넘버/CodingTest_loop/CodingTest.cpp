#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> numbers, int target) {
    int answer = 0;

    struct info
    {
        int index, sum;
    };

    stack<info> st;
    st.push({ 0,0 });

    while (!st.empty())
    {
        info now = st.top();
        st.pop();

        if (now.index < numbers.size())
        {
            st.push({ now.index + 1, now.sum + numbers[now.index] });
            st.push({ now.index + 1, now.sum - numbers[now.index] });
        }
        else if(now.sum == target) answer++;
    }

    return answer;
}

int main()
{
    cout << solution({ 1,1,1,1,1 }, 3);
}