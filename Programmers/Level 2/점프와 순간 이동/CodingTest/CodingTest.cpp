#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
    int ans = 0;
    while (n > 0)
    {
        ans += n % 2;
        n /= 2;
    }

    return ans;
}

int main()
{
    cout << solution(5);

	return 0;
}