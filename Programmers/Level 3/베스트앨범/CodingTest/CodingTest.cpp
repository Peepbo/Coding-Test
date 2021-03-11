#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<pair<string, int>> v;
unordered_map<string, int> genrePlays;

class Song
{
public:
    Song(string str, int a, int b)
    {
        genre = str;
        play = a;
        idx = b;
    }

    string genre;
    int play;
    int idx;
};

bool compare(pair<string, int> a, pair<string, int> b)
{
    return a.second > b.second;
}

bool compare2(Song a, Song b)
{
    if (a.genre != b.genre) return genrePlays[a.genre] > genrePlays[b.genre];
    if (a.play != b.play) return a.play > b.play;
    return a.idx < b.idx;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;

    unordered_map<string, vector<int>> data;

    vector<Song> songs;

    for (int i = 0; i < genres.size(); i++)
    {
        string genre = genres[i];
        int play = plays[i];

        data[genre].emplace_back(play);
        genrePlays[genre] += play;

        songs.emplace_back(Song(genre, play, i));
    }

    v.assign(genrePlays.begin(), genrePlays.end());
    sort(v.begin(), v.end(), compare);

    int num = 100;
    for (const auto& it : v)
    {
        genrePlays[it.first] = num;
        num--;
    }

    sort(songs.begin(), songs.end(), compare2);

    string saveGenre = songs.front().genre;
    int cnt = 0;
    int genreNum = 1;

    for (const auto& it : songs)
    {
        if (saveGenre == it.genre)
        {
            if (cnt < 2)cnt++;

            else if (cnt == 2)
            {
                continue;
            }
        }

        else
        {
            saveGenre = it.genre;
            genreNum++;
            cnt = 1;

            if (genreNum == 3)break;
        }

        answer.emplace_back(it.idx);
    }

    return answer;
}

int main()
{
    solution({ "classic","pop","classic","classic","pop" }, { 500,600,150,800,2500 });
    return 0;
}