#include <string>
#include <iostream>

using namespace std;

int lowCost = 100000;
string sub[1000];

void optimization(string s, int w)
{
    int left = 0;

    int len = s.length();

    int culLen = len / w;
    if (len % w != 0)culLen++;

    for (int i = 0; i < culLen; i++)
    {
        sub[i] = s.substr(left, w);
        left += w;
    }

    int pivot = 1;
    int cost = 0;

    string save = "";
    int combo = 1;
    while (pivot - 1 < culLen)
    {
        if (sub[pivot - 1].length() == sub[pivot].length() &&
            sub[pivot - 1] == sub[pivot])
        {
            if (save == sub[pivot])
            {
                combo++;
            }

            else
            {
                cost += sub[pivot].length();

                save = sub[pivot];
                combo = 2;
            }
        }

        else
        {
            if (combo > 1)
            {
                cost += to_string(combo).length();
                combo = 1;
            }

            else
            {
                cost += sub[pivot - 1].length();
            }

            save.clear();
        }

        pivot++;
    }

    if (combo > 1) cost += to_string(combo).length();

    if (lowCost > cost)lowCost = cost;
}

int solution(string s) {
    int len = s.length();

    if (len <= 1)return len;

    bool isCollect = true;

    char ch = s[0];
    for (const auto& c : s)
    {
        if (ch != c)
        {
            isCollect = false;
            break;
        }
    }
    if (isCollect)
    {
        return to_string(len).length() + 1;
    }

    int maxIdx = len / 2;
    while (maxIdx > 0)
    {
        optimization(s, maxIdx--);
    }

    return lowCost;
}

int main()
{
	cout << solution("aabbaccc");

	//for (const auto& it : output)
	//{
	//	cout << it << ' ';
	//}

	return 0;
}