#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

bool compare(tuple<string, string, int> a, tuple<string, string, int> b)
{
    if (get<1>(a) != get<1>(b)) return get<1>(a) < get<1>(b);
    else if (get<2>(a) != get<2>(b)) return get<2>(a) < get<2>(b);
    return false;
}

vector<string> solution(vector<string> files) {
    vector<string> answer;

    vector<tuple<string, string, int>> v;
    string name = "", head = "";
    int number = 0;

    int writeOrder, start;
    int len1 = files.size(), len2;
    for (int i = 0; i < len1; i++)
    {
        start = 0;
        writeOrder = 0;

        name = files[i];
        len2 = files[i].size();
        for (int j = 0; j <= len2; j++)
        {
            if (writeOrder == 0)
            {
                if (isdigit(files[i][j]))
                {
                    head = files[i].substr(start, j - start);

                    transform(head.begin(), head.end(), head.begin(), ::tolower);

                    start = j;
                    writeOrder++;
                }
            }

            else
            {
                cout << files[i][j] << '\n';
                if (!isdigit(files[i][j]) && files[i][j] != '0')
                {
                    number = stoi(files[i].substr(start, j - start));
                    cout << number << '\n';
                    break;
                }
            }
        }

        v.emplace_back(name, head, number);
    }

    stable_sort(v.begin(), v.end(), compare);

    for (const auto& it : v) answer.emplace_back(get<0>(it));

    return answer;
}

int main()
{
    solution({ "img000012345","img1.png","img2","IMG02" });

	return 0;
}