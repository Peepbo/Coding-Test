#include <unordered_set>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    unordered_set<string> duplicate;

    char lWord, rWord;

    lWord = words[0].back();
    duplicate.emplace(words.front());

    int len = words.size();
    for (int i = 1; i < words.size(); i++)
    {
        if (duplicate.find(words[i]) == duplicate.end())
            duplicate.emplace(words[i]);
        else
            return { (i % n) + 1,(i / n) + 1 };

        rWord = words[i].front();

        if (lWord != rWord)
            return { (i % n) + 1 ,(i / n) + 1 };

        lWord = words[i].back();
    }

    return { 0,0 };
}

int main()
{
    vector<int> output = solution(3, { "tank", "kick", "know", "wheel", "land", "dream", "mother", "robot", "tank" });

    for (const auto& it : output)
    {
        cout << it << ' ';
    }
	return 0;
}