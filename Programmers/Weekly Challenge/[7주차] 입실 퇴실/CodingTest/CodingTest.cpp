#include <iostream>

#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> enter, vector<int> leave) {
    const int size = enter.size();
    int eIdx = 0, lIdx = 0, newPerson, outPerson;
    vector<int> answer(size);
    set<int> room;

    room.insert(enter[eIdx++]);

    while (eIdx < size) {
        if (room.find(leave[lIdx]) != room.end()) {
            outPerson = leave[lIdx++];

            room.erase(outPerson);
        }

        else {
            newPerson = enter[eIdx++];

            for (const auto& inPerson : room) {
                answer[inPerson - 1]++;
                answer[newPerson - 1]++;
            }

            room.insert(newPerson);
        }
    }

    return answer;
}

int main() {
    solution({ 1,4,2,3 }, { 2,1,3,4 });
	return 0;
}