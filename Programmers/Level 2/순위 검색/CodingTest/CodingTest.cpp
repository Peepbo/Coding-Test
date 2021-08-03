#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>

using namespace std;

unordered_map<string, int> Map;
vector<int> List[4][3][3][3];

vector<int> solution(vector<string> info, vector<string> query) {
    Map["-"] = 0;
    Map["cpp"] = 1;
    Map["java"] = 2;
    Map["python"] = 3;

    Map["backend"] = 1;
    Map["frontend"] = 2;

    Map["junior"] = 1;
    Map["senior"] = 2;

    Map["chicken"] = 1;
    Map["pizza"] = 2;

    for (auto str : info) {
        stringstream ss(str);
        string a, b, c, d;
        int score;

        ss >> a >> b >> c >> d >> score;
        int arr[4]{ Map[a], Map[b],Map[c],Map[d] };

        for (int i = 0; i < 2; i++) { //언어
            for (int j = 0; j < 2; j++) { //직군
                for (int k = 0; k < 2; k++) { //경력
                    for (int l = 0; l < 2; l++) { //소울 푸드
                        int first = i == 0 ? 0 : Map[a];
                        int second = j == 0 ? 0 : Map[b];
                        int third = k == 0 ? 0 : Map[c];
                        int fourth = l == 0 ? 0 : Map[d];

                        List[first][second][third][fourth].push_back(score);

                        //if (List[first][second][third][fourth].size() > 1) {
                        //    sort(List[first][second][third][fourth].begin(),
                        //        List[first][second][third][fourth].end());
                        //}
                    }
                }
            }
        }
    }

    for (int i = 0; i < 4; i++) { //언어
        for (int j = 0; j < 3; j++) { //직군
            for (int k = 0; k < 3; k++) { //경력
                for (int l = 0; l < 3; l++) { //소울 푸드
                    sort(List[i][j][k][l].begin(), List[i][j][k][l].end());
                }
            }
        }
    }

    vector<int> answer;
    for (auto str : query) {
        stringstream ss(str);
        string a, b, c, d, temp;
        int score;
        ss >> a >> temp >> b >> temp >> c >> temp >> d >> score;

        auto& slist = List[Map[a]][Map[b]][Map[c]][Map[d]];
        auto low = lower_bound(slist.begin(), slist.end(), score);
        answer.push_back(slist.end() - low);
    }

    return answer;
}

int main() {

	return 0;
}