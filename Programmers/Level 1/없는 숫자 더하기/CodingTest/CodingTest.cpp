#include <iostream>

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 9 * 10 / 2;

    for (const int& num : numbers) {
        answer -= num;
    }
    return answer;
}

int main() {

	return 0;
}