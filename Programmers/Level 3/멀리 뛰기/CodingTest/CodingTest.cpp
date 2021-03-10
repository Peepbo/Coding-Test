#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

long long fib(int num)
{
    array<long long, 2> arr{ 0,1 };
    
    for (int i = 2; i < num + 1; i++)
    {
        arr[0] = (arr[0] + arr[1]) % 1234567;
        swap(arr[0], arr[1]);
    }

    return arr.back();
}

long long solution(int n) {
    return fib(n + 1);
}

int main()
{
    cout << solution(3);

	return 0;
}