#include <string>
#include <vector>
#include <queue>

using namespace std;

bool visit[300][300];

const int mX[4]{ 0,0,-1,1 }, mY[4]{ -1,1,0,0 };

vector<vector<int>> Land;
int Height, MaxRange, VisitCount, Need;

struct Option {
    int x, y, c;
};

struct compare {
    bool operator() (const Option& a, const Option& b) {
        if (a.c != b.c)return a.c > b.c;
        if (a.x != b.x)return a.x > b.x;
        return a.y > b.y;
    }
};

priority_queue<Option, vector<Option>, compare> pq;

void bfs(int x, int y) {
    if (visit[y][x])return;

    VisitCount++;
    visit[y][x] = true;

    int _x, _y, _height;

    for (int i = 0; i < 4; i++) {
        _x = x + mX[i];
        _y = y + mY[i];

        if (_x < 0 || _x == MaxRange)continue;
        if (_y < 0 || _y == MaxRange)continue;
        if (visit[_y][_x])continue;

        _height = abs(Land[y][x] - Land[_y][_x]);

        if (_height > Height) {
            pq.push({ _x,_y,_height });
        }
        else {
            bfs(_x, _y);
        }
    }
}

int solution(vector<vector<int>> land, int height) {
    Land = land;
    Height = height;
    MaxRange = land.size();

    const int count = MaxRange * MaxRange;

    bfs(0, 0);

    while (VisitCount < count) {
        Option top = pq.top();
        pq.pop();

        while (visit[top.y][top.x]) {
            top = pq.top();
            pq.pop();
        }

        Need += top.c;

        bfs(top.x, top.y);
    }

    return Need;
}

int main(void) {
    solution({
        {10, 11, 10, 11},
        {2, 21, 20, 10},
        {1, 20, 21, 11},
        {2, 1, 2, 1} }, 1);

	return 0;
}