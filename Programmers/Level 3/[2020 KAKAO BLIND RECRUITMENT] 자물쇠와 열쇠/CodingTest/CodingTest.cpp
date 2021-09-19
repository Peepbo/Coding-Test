#include <string>
#include <vector>
#include <set>

using namespace std;

int MaxKey, MaxLock;

struct Point {
    int x, y;

    bool operator<(const Point& ptr)const {
        if (y != ptr.y)return y > ptr.y;
        return x > ptr.x;
    }
    Point operator-(const Point& ptr) {
        return Point({ x - ptr.x, y - ptr.y });
    }
    Point operator-(const Point& ptr) const{
        return Point({ x - ptr.x, y - ptr.y });
    }
    Point operator-=(const Point& ptr) {
        (*this) = (*this) - ptr;
        return *this;
    }
};

class Lock {
public:
    Lock(const vector<vector<int>>& lock) {
        vector<Point> lockG, lockP;

        for (int y = 0; y < MaxLock; y++) {
            for (int x = 0; x < MaxLock; x++) {
                if (lock[y][x] == 1) {
                    lockG.emplace_back(Point{ x,y });
                }
                else {
                    lockP.emplace_back(Point{ x,y });
                }
            }
        }

        if (lockP.empty())return;

        //홈의 좌측 상단 기준으로 상대 좌표로 바꿈
        const Point ptr = lockP[0];
        for (const Point& p : lockP) {
            groove.insert(p - ptr);
        }
        for (const Point& p : lockG) {
            protrusion.insert(p - ptr);
        }
    }

    bool isCollect(const vector<Point>& keyG) const{
        int count = 0;

        for (const Point& ptr : keyG) {
            if (protrusion.find(ptr) != protrusion.end())return false;
            if (groove.find(ptr) == groove.end())continue;

            count++;
        }

        return count == groove.size();
    }
public:
    set<Point> groove, protrusion;
};

class Key {
public:
    Key(const vector<vector<int>>& key) {
        vector<Point> keyG;

        for (int y = 0; y < MaxKey; y++) {
            for (int x = 0; x < MaxKey; x++) {
                if (key[y][x] == 0) continue;

                keyG.emplace_back(Point{ x,y });
            }
        }

        blockCount = keyG.size();

        rotation[0] = keyG;
        for (int i = 1; i < 4; i++) {
            for (int j = 0; j < blockCount; j++) {
                rotation[i].emplace_back(Point{ MaxKey - 1 - rotation[i - 1][j].y, rotation[i - 1][j].x });
            }
        }
    }

    void changeCriteria(const int& rotIdx, const int& criIdx) {
        const Point criPtr = rotation[rotIdx][criIdx];

        for (int i = 0; i < blockCount; i++) {
            rotation[rotIdx][i] -= criPtr;
        }
    }
public:
    size_t blockCount;
    vector<Point> rotation[4];
};

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    MaxKey = key.size();
    MaxLock = lock.size();

    const Lock s_lock(lock);
    if (s_lock.groove.empty())return true;

    Key s_key(key);

    //i번째 회전, j번째 축을 기준(0,0)으로 자물쇠에 넣어본다.
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < s_key.blockCount; j++) {
            s_key.changeCriteria(i, j);

            if (s_lock.isCollect(s_key.rotation[i]) == false)continue;

            return true;
        }
    }

    return false;
}

int main() {
    solution({ {0,0,0},{1,0,0},{0,1,1} }, { {1,1,1},{1,1,0},{1,0,1} });

	return 0;
}