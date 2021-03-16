#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
	int answer = 1;
	unordered_map<string, int> m;

	for (const auto& it : clothes)
		m[it[1]]++;

	for (const auto& it : m)
		answer *= it.second + 1;

	return answer - 1;
}

int main()
{
    cout << solution({ 
		{ "yellowhat", "headgear"},
		{ "bluesunglasses", "eyewear" },
		{ "green_turban", "headgear" } });

    return 0;
}