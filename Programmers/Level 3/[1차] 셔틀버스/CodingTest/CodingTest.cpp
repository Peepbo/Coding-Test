#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class suttleBus {
public:
	suttleBus(int n, int t, int m):
		number{ n }, interval{ t }, capacity{ m },
		total{ 540 }, answer{ 0 } {}

	void addCrew(vector<int> times) {
		int idx = 0, nCapacity = 0;
		const int lastBusTime = total + (interval * (number - 1));
		int lastCrewTime = -1;

		while (number) {
			// 종료 조건
			// 1. 모든 크루원을 검사했을 때
			// 2. 현재 크루원이 버스 마지막 시간보다 늦을 때
			if (idx == times.size() || lastBusTime < times[idx]) {
				break;
			}

			// 탑승 조건
			// 1. 크루원이 버스 시간에 맞춰 왔을 때
			// 2. 버스의 잔여 좌석이 있을 때
			if (total >= times[idx]) {
				nCapacity++;
				lastCrewTime = times[idx];
				idx++;

				if (nCapacity == capacity) {
					nCapacity = 0;
					number--;
					total += interval;
				}
			}
			else {
				nCapacity = 0;
				number--;
				total += interval;
			}
		}

		// number가 valid 하다면? (n>0)
		if (number > 0) {
			answer = lastBusTime;
		}
		else {
			// 만약 number가 valid하지 않다면 (n=0)?
			// 가장 마지막에 탑승한 크루 시간 - 1
			answer = lastCrewTime - 1;
		}
	}

public:
	int number, interval, capacity;
	int total;
	int answer;
};

vector<int> vectorStringToTimes(vector<string> timetable) {
	vector<int> times(timetable.size());
	string timeData;
	int hour, minute;

	for (int i = 0; i < timetable.size(); i++) {
		timeData = timetable[i];

		hour = (timeData[0] - '0') * 10 + (timeData[1] - '0');
		minute = (timeData[3] - '0') * 10 + (timeData[4] - '0');

		times[i] = hour * 60 + minute;
	}

	return times;
}

string intToStringTime(int iTime) {
	string output;
	int hour = iTime / 60;
	int minute = iTime % 60;
	output += hour / 10 + '0';
	output += hour % 10 + '0';
	output += ':';
	output += minute / 10 + '0';
	output += minute % 10 + '0';
	return output;
}

string solution(int n, int t, int m, vector<string> timetable) {
	string answer = "";
	suttleBus bus(n, t, m);

	vector<int> crewTime = vectorStringToTimes(timetable);
	sort(crewTime.begin(), crewTime.end());

	bus.addCrew(crewTime);

	return intToStringTime(bus.answer);
}

int main(void) {
	//cout << solution(1, 1, 5, { "08:00", "08:01", "08:02", "08:03" });
	//cout << solution(2, 1, 2, { "09:00", "09:00", "09:00", "09:00" });
	//cout << solution(2, 10, 2, { "09:10", "09:09", "08:00" });
	//cout << solution(1, 1, 5, { "00:01", "00:01", "00:01", "00:01", "00:01" });
	//cout << solution(1, 1, 1, { "23:59" });
	//cout << solution(10, 60, 45, { "23:59","23:59" ,"23:59" ,"23:59" ,"23:59" ,"23:59" ,"23:59" ,"23:59" ,"23:59" ,"23:59" ,"23:59" ,"23:59" ,"23:59" ,"23:59" ,"23:59" ,"23:59" });
	//10, 1, 5, ["09:00", "09:00", "09:00", "09:00", "09:00"] // "09:09"
	//cout << solution(3, 30, 2, { "09:00","09:00","09:10","09:20","09:30","09:59","11:00" });
	return 0;
}