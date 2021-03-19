#include <iostream>
#include <vector>
#include <array>

int Fib(int n)
{
    std::array<int, 2> arr{ 0,1 };

    for (int i = 2; i < n + 1; i++)
    {
        arr[0] = (arr[0] + arr[1]) % 1234567;
        std::swap(arr[0], arr[1]);
    }

    return arr[1];
}

int solution(int n) {
    return Fib(n);
}

int main()
{

	return 0;
}