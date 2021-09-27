#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int hW = 1, hH = 1, w, h;

    for (const auto& vec : sizes) {
        w = vec[0];
        h = vec[1];

        if (w < h)swap(w, h);

        hW = max(hW, w);
        hH = max(hH, h);
    }

    return hW * hH;
}

int main(void) {
    solution({ { 60,50 }, { 30,70 }, { 60,30 }, { 80,40 } });

	return 0;
}