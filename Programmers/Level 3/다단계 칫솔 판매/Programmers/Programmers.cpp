#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Employee {
public:
	Employee* referrer = nullptr;
	int profit = 0;
public:
	void share_the_profits(int totalProfit) {
		if (totalProfit == 0 || referrer == nullptr)return;

		int referrerProfit = totalProfit * 0.1f;
		profit += totalProfit - referrerProfit;

		referrer->share_the_profits(referrerProfit);
	}
};

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
	vector<int> answer(enroll.size());
	map<string, Employee*> m;
	const int quaternion = enroll.size(), number_of_sellers = seller.size();

	for (int i = 0; i < quaternion; i++) {
		if (m.find(enroll[i]) == m.end())
			m[enroll[i]] = new Employee;
		if (m.find(referral[i]) == m.end())
			m[referral[i]] = new Employee;

		m[enroll[i]]->referrer = m[referral[i]];
	}

	for (int i = 0; i < number_of_sellers; i++) {
		int totalProfit = amount[i] * 100;

		m[seller[i]]->share_the_profits(totalProfit);
	}

	for (int i = 0; i < quaternion; i++) {
		answer[i] = m[enroll[i]]->profit;
	}

	return answer;
}

int main()
{
	vector<string> enroll{ "john","mary","edward","sam","emily","jaimie","tod","young" };
	vector<string> referral{ "-","-","mary","edward","mary","mary","jaimie","edward" };
	vector<string> seller{ "young","john","tod","emily","mary" };
	vector<int> amount{ 12,4,2,5,10 };

	auto vec = solution(enroll, referral, seller, amount);

	for (auto num : vec) {
		cout << num << ' ';
	}
}