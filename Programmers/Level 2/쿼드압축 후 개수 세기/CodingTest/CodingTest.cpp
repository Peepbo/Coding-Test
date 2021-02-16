#include <iostream>
#include <string>
#include <vector>

using namespace std;

int ns[2] = { 0,0 };
void check(vector<vector<int>>& arr, int si, int sj, int sz) {
    int val = arr[si][sj];
    if (sz == 1) {
        ns[val]++;
        return;
    }
    bool mergable = true;
    for (int i = si; i < si + sz; i++) {
        for (int j = sj; j < sj + sz; j++) {
            if (arr[i][j] != val) {
                mergable = false;
            }
        }
    }
    if (mergable) {
        ns[val]++;
    }
    else {
        sz = sz / 2;
        check(arr, si, sj, sz);
        check(arr, si, sj + sz, sz);
        check(arr, si + sz, sj, sz);
        check(arr, si + sz, sj + sz, sz);
    }
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    check(arr, 0, 0, arr.size());
    answer = { ns[0],ns[1] };
    return answer;
}

int main()
{
	auto v = solution({
		{1, 1, 1, 1, 1, 1, 1, 1},
		{0, 1, 1, 1, 1, 1, 1, 1},
		{0, 0, 0, 0, 1, 1, 1, 1},
		{0, 1, 0, 0, 1, 1, 1, 1},
		{0, 0, 0, 0, 0, 0, 1, 1},
		{0, 0, 0, 0, 0, 0, 0, 1},
		{0, 0, 0, 0, 1, 0, 0, 1},
		{0, 0, 0, 0, 1, 1, 1, 1} });
	for (const auto& it : v)
	{
		cout << it << ' ';
	}

	return 0;
}