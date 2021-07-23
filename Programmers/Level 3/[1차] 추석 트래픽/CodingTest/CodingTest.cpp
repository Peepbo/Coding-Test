#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Time {
	int start, end;
};

Time split(const string& str) {
	//2016-09-15 20:59:57.421 0.351s
	string hour, minut, mSecond, processing_mSecond;
	int h, m, ms, pms;

	hour = str.substr(11, 2);
	minut = str.substr(14, 2);
	mSecond = str.substr(17, 2) + str.substr(20, 3);

	processing_mSecond = str.substr(24);
	processing_mSecond.pop_back();

	if (processing_mSecond.size() != 1) // 2s -> 2
		processing_mSecond.erase(processing_mSecond.begin() + 1);
	while (processing_mSecond.size() != 4) { // 2(s) -> 2000(ms)
		processing_mSecond.push_back('0');
	}

	h = stoi(hour) * 3600 * 1000;
	m = stoi(minut) * 60 * 1000;
	ms = stoi(mSecond);
	pms = stoi(processing_mSecond);

	return { h + m + ms - pms + 1, h + m + ms };
}

int solution(vector<string> lines) {
	int answer = 0, tmp = 0, count, endTime;

	vector<Time> times(lines.size());
	for (const string& str : lines) {
		times[tmp++] = split(str);
	}

	for (int i = 0; i < times.size(); i++) {
		count = 1;
		endTime = times[i].end;

		for (int j = i + 1; j < times.size(); j++) {
			if (times[j].start < endTime + 1000) {
				count++;
			}
		}
		answer = max(answer, count);
	}

	return answer;
}

int main() {
	cout << solution({ "2016-09-15 20:59:57.421 0.351s",
"2016-09-15 20:59:58.233 1.181s",
"2016-09-15 20:59:58.299 0.8s",
"2016-09-15 20:59:58.688 1.041s",
"2016-09-15 20:59:59.591 1.412s",
"2016-09-15 21:00:00.464 1.466s",
"2016-09-15 21:00:00.741 1.581s",
"2016-09-15 21:00:00.748 2.31s",
"2016-09-15 21:00:00.966 0.381s",
"2016-09-15 21:00:02.066 2.62s" });

	return 0;
}