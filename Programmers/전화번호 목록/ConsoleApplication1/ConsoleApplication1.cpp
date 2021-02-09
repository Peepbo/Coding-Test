#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {

    sort(phone_book.begin(), phone_book.end());

    string str = phone_book.front();

    int count = 0;

    for (int i = 1; i < phone_book.size(); i++)
    {
        for (int j = 0; j < str.size(); j++)
        {
            if (str[j] != phone_book[i][j])break;

            count++;
        }

        if (count == str.size())return false;
        else count = 0;
    }

    return true;
}

void main()
{
    cout << solution({ "119","97674223","1195524421" });
}