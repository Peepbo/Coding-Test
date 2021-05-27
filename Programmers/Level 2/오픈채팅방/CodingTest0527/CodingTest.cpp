#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {
    struct chatData
    {
        char behavior;
        string id;
    };

    vector<string> answer;
    vector<chatData> saveChatData;

    unordered_map<string, string> nickNameMap;

    istringstream ss;
    string behavior, id, nickName;

    for (const string& stringData : record)
    {
        ss.str(stringData);
        ss >> behavior >> id >> nickName;

        if (!nickName.empty()) nickNameMap[id] = nickName;
        if (behavior[0] != 'C') saveChatData.push_back({ behavior[0], id });

        ss.clear();
        nickName = "";
    }

    for (const chatData& data : saveChatData)
    {
        if (data.behavior == 'E') 
            answer.emplace_back(nickNameMap[data.id] + "님이 들어왔습니다.");
        else
            answer.emplace_back(nickNameMap[data.id] + "님이 나갔습니다.");
    }

    return answer;
}

int main()
{
    solution({ 
        "Enter uid1234 Muzi",
        "Enter uid4567 Prodo",
        "Leave uid1234",
        "Enter uid1234 Prodo",
        "Change uid4567 Ryan" });
}