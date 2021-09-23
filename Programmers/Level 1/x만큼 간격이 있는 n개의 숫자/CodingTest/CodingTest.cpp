#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer(n);

    for (int16_t i = 0; i < n; i++) {
        answer[i] = (long long)x * (i + 1);
    }

    return answer;
}

int main() {

	return 0;
}