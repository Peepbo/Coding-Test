#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;

    unordered_map<string, int> mp;
    string write, word;
    for (int i = 0; i < 26; i++)
    {
        write = 'A' + i;
        mp[write] = i + 1;
    }

    write = msg[0];

    int len = msg.size();
    for (int i = 1; i <= len; i++)
    {
        word = write + msg[i];
        if (mp[word] == 0)
        {
            answer.emplace_back(mp[write]);
            mp[word] = mp.size();

            write = msg[i];
        }
        else
        {
            write += msg[i];
        }
    }

    return answer;
}

int main()
{
    auto output = solution("ABABABABABABABAB");

    for (auto& it : output) cout << it << '-';

	return 0;
}