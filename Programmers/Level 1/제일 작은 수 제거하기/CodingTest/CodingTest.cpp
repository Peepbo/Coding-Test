#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    int minNumber = arr.front(), minNumberIndex = 0, index = 0;

    for (const int& number : arr)
    {
        if (number < minNumber)
        {
            minNumber = number;
            minNumberIndex = index;
        }

        index++;
    }

    arr.erase(arr.begin() + minNumberIndex);

    if (arr.empty())
        arr.emplace_back(-1);

    return arr;
}

int main()
{

}