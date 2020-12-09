#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int s2i(string str)
{

    vector<char> charV;

    int number = 0;

    bool minus = false;
    if (str[0] == '-')minus = true;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '-')continue;

        charV.push_back(str[i]);
    }

    int index = str.length() - 1;
    if (minus)index -= 1;

    int mul = 10;

    while (index >= 0)
    {
        int len = str.length() - 1;
        if (minus) len = str.length() - 2;

        if(index == len) number += charV[index] - '0';

        else
        {
            number += (charV[index] - '0') * mul;
            mul *= 10;
        }
        
        index--;
    }

    if (minus)number *= -1;

    return number;
}

string solution(string s) {
    string answer = "";

    istringstream iss(s);
    string token;

    vector<string> strV;
    vector<int> intV;

    while (getline(iss,token,' '))
    {
        strV.push_back(token);
    }

    for (int i = 0; i < strV.size(); i++)
    {
        intV.push_back(s2i(strV[i]));
    }

    sort(intV.begin(), intV.end());
    
    answer += to_string(intV.front());
    answer += " ";
    answer += to_string(intV.back());

    return answer;
}

int main()
{
    cout << solution("-1 -2 -3 -4");
}