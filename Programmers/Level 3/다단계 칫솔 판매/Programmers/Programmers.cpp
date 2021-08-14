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
	void share_the_profits(int referrerProfit) {
		if (referrerProfit == 0 || referrer == nullptr)return;

		share_the_profits_recur(referrer, referrerProfit);
	}
private:
	void share_the_profits_recur(Employee* employee, int referrerProfit) {
		if (referrerProfit == 0 || employee == nullptr)return;

		int nextProfit = referrerProfit * 0.1f;
		employee->profit += referrerProfit - nextProfit;
		share_the_profits_recur(employee->referrer, nextProfit);
	}
};

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
	vector<int> answer;
	map<string, Employee*> m;

	for (int i = 0; i < enroll.size(); i++) {
		if (m.find(enroll[i]) == m.end())
			m[enroll[i]] = new Employee;
		if (m.find(referral[i]) == m.end())
			m[referral[i]] = new Employee;

		m[enroll[i]]->referrer = m[referral[i]];
	}

	for (int i = 0; i < seller.size(); i++) {
		int totalProfit = amount[i] * 100;
		int referrerProfit = totalProfit * 0.1f;
		
		m[seller[i]]->profit += totalProfit - referrerProfit;
		m[seller[i]]->share_the_profits(referrerProfit);
	}

	for (int i = 0; i < enroll.size(); i++) {
		answer.emplace_back(m[enroll[i]]->profit);
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