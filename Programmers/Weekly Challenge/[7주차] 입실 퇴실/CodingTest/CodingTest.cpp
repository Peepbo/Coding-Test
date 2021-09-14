#include <iostream>

#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> enter, vector<int> leave) {
    const int size = enter.size();
    int eIdx = 0, lIdx = 0;
    vector<vector<bool>> metList(size + 1, vector<bool>(size + 1, false));
    vector<int> answer(size);
    set<int> room;

    room.insert(enter[eIdx++]);

    while (eIdx < size) {
        if (room.find(leave[lIdx]) == room.end()) {
            room.insert(enter[eIdx++]);

            for (const auto& p1 : room) {
                for (const auto& p2 : room) {
                    if (p1 == p2)continue;
                    if (metList[p1][p2] || metList[p2][p1])continue;

                    metList[p1][p2] = metList[p2][p1] = true;
                    answer[p1 - 1]++;
                    answer[p2 - 1]++;
                }
            }
        }
        else {
            room.erase(leave[lIdx++]);
        }
    }

    return answer;
}

int main() {
    solution({ 1,4,2,3 }, { 2,1,3,4 });
	return 0;
}