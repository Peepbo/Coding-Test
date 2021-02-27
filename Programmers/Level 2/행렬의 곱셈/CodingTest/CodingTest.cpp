#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int len0 = arr1.size();
    int len1 = arr1[0].size();
    int len2 = arr2[0].size();
    vector<int> v;

    for (int i = 0; i < len0; i++)
    {
        int hPivot = 0;
        int wPivot = 0;
        
        for (int k = 0; k < len2; k++)
        {
            v.emplace_back(arr1[i][0] * arr2[0][k]);
        }

        hPivot++;
        while (hPivot < len1)
        {
            wPivot = 0;
            while (wPivot < len2)
            {
                v[wPivot] += arr1[i][hPivot] * arr2[hPivot][wPivot];
                
                wPivot++;
            }

            hPivot++;
        }

        answer.emplace_back(v);
        v.clear();
    }

    return answer;
}

int main()
{
    auto o = solution({ {1,2},{3,4} }, { {1,4,7},{2,5,8 } });
    //auto o = solution({ {2, 3, 2}, { 4,2,4 }, { 3,1,4 } }, { {5,4,3},{2,4,1},{3,1,1} });

    for (const auto& it : o)
    {
        for (const auto& t : it)
        {
            cout << t << ' ';
        }
        cout << '\n';
    }

	return 0;
}