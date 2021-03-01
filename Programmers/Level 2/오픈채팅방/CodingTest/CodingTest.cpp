#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

unordered_map<string, string> user;
vector<pair<char, string>> chat;

void saveMap(vector<string>& rec)
{
    string result[3];
    stringstream ss;
    
    int len = rec.size();
    for (int i = 0; i < len; i++)
    {
        ss.str(rec[i]);

        ss >> result[0] >> result[1] >> result[2];

        if (rec[i][0] != 'L')user[result[1]] = result[2];
        chat.emplace_back(rec[i][0], result[1]);
        ss.clear();
    }
}

vector<string> changeText()
{
    vector<string> result;

    int len = chat.size();
    for (int i = 0; i < len; i++)
    {
        if (chat[i].first == 'C')continue;

        if (chat[i].first == 'E')
        {
            result.emplace_back(user[chat[i].second] + "님이 들어왔습니다.");
        }
        else
        {
            result.emplace_back(user[chat[i].second] + "님이 나갔습니다.");
        }
    }

    return result;
}

vector<string> solution(vector<string> record) {
    saveMap(record);
    return changeText();
}


int main()
{
    auto a = solution({ "Enter uid1234 Muzi" , "Enter uid4567 Prodo", "Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"});

    for (const auto& i : a)
    {
        cout << i << '\n';
    }

	return 0;
}