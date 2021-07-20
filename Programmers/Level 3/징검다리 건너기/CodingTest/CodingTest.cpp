#include <iostream>

#include <string>
#include <vector>

using namespace std;

int FindMaxElement(const vector<int>& v) {
    int output = 0;
    for (const int& it : v) {
        output = max(output, it);
    }

    return output;
}

bool BinarySearch(const vector<int>& stones, const int& mid, const int& k) {
    int count = 0;
    for (const int& stone : stones) {
        if (stone - mid <= 0)
            count++;
        else
            count = 0;

        if (count == k)
            return false;
    }

    return true;
}

int solution(vector<int> stones, int k) {
    int first = 1, last = FindMaxElement(stones);

    while (first <= last) {
        int mid = (first + last) / 2;

        if (BinarySearch(stones, mid, k))
            first = mid + 1;
        else
            last = mid - 1;
    }

    return first;
}

int main()
{
    cout << solution({ 2, 4, 5, 3, 2, 1, 4, 2, 5, 1 }, 3);

	return 0;
}