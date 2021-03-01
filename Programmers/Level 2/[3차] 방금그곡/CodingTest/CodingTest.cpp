#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

unordered_map<string, char> mp;

int h0, h1, m0, m1;

int getTime(const string& clock)
{
    h0 = stoi(clock.substr(0, 2));
    m0 = stoi(clock.substr(3, 2));
    h1 = stoi(clock.substr(6, 2));
    m1 = stoi(clock.substr(9, 2));

    return (h1 - h0) * 60 + (m1 - m0);
}

void addMap()
{
    mp["C#"] = 'c';
    mp["D#"] = 'd';
    mp["F#"] = 'f';
    mp["G#"] = 'g';
    mp["A#"] = 'a';
}

string change(const string& str)
{
    string out = "";

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i + 1] == '#')
        {
            out += mp[str.substr(i, 2)];
            i++;
        }
        else out += str[i];
    }

    return out;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    string melody = "", title = "";
    addMap();
    melody = change(m);

    int curTime = 0;
    int lastTime = 0;

    for (int i = 0; i < musicinfos.size(); i++)
    {
        string tmp = "", music = "";

        curTime = getTime(musicinfos[i].substr(0, 11));

        for (int j = 12; musicinfos[i].size(); j++)
        {
            if (musicinfos[i][j] == ',')
            {
                title = musicinfos[i].substr(12, j - 12);
                tmp = musicinfos[i].substr(j + 1);
                break;
            }
        }

        music = change(tmp);

        tmp = music;
        if (music.size() < curTime)
        {
            while (music.size() < curTime)
            {
                music += tmp;
            }
        }
        else music = music.substr(0, curTime);

        if (music.find(melody) != -1)
        {
            if (lastTime < curTime)
            {
                answer = title;
                lastTime = curTime;
            }
        }
    }

    return answer;
}

int main()
{
    cout << solution("A#C#DGA", { "12:00,12:14,HELLO,CDEFGAB" });

    return 0;
}