#include <string>
#include <vector>

using namespace std;

string solution(int n) {
	string answer;
	string waterMelon[2]{ "수","박" };

	for (int i = 0; i < n; i++){
		answer += waterMelon[i % 2];
	}
	return answer;
}

int main()
{
	return 0;
}