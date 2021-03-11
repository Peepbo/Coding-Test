#include <iostream>
#include <vector>
#include <array>

using namespace std;

int fib(int num)
{
    array<int, 2> arr{ 0,1 };

    for (int i = 2; i < num + 1; i++)
    {
        arr[0] = (arr[0] + arr[1]) % 1000000007;
        swap(arr[0], arr[1]);
    }

    return arr.back();
}

int solution(int n) {
    return fib(n);
}

int main()
{
    solution(3);

	return 0;
}