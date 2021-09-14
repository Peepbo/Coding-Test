#include <iostream>

#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> enter, vector<int> leave) {
    const int size = enter.size();
    int eIdx = 0, lIdx = 0, newPerson, outPerson;
    vector<vector<bool>> metList(size + 1, vector<bool>(size + 1, false));
    vector<int> answer(size);
    set<int> room;

    room.insert(enter[eIdx++]);

    while (eIdx < size) {
        if (room.find(leave[lIdx]) == room.end()) {
            newPerson = enter[eIdx++];

            for (const auto& inPerson : room) {
                if (!metList[inPerson][newPerson]) {
                    metList[inPerson][newPerson] = metList[newPerson][inPerson] = true;

                    answer[inPerson - 1]++;
                    answer[newPerson - 1]++;
                }
            }

            room.insert(newPerson);
        }
        else {
            outPerson = leave[lIdx++];

            room.erase(outPerson);
        }
    }

    return answer;
}

int main() {
    solution({ 1,4,2,3 }, { 2,1,3,4 });
	return 0;
}