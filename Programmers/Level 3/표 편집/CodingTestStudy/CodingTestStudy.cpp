#include <iostream>

#include <string>
#include <vector>
#include <stack>

using namespace std;

struct Node {
	int val;
	Node* prev, * next;

	Node(int value) :
		val{ value }, prev{ nullptr }, next{ nullptr }{}
};

string solution(int n, int k, vector<string> cmd) {
	string answer(n, 'X');

	Node* head, * tail, * now;
	stack<Node*> logs;
	vector<Node> vec(n, Node(0));

	for (int i = 1; i < n; i++) {
		vec[i].val = i;
		vec[i].prev = &vec[i - 1];
		vec[i - 1].next = &vec[i];
	}

	head = &vec.front();
	tail = &vec.back();

	now = k < (n / 2) ? head : tail;

	if (now == head) {
		while (now->val != k) {
			now = now->next;
		}
	}
	else { //now == tail
		while (now->val != k) {
			now = now->prev;
		}
	}

	for (const string& command : cmd) {
		if (command[0] == 'U' || command[0] == 'D') {
			int cnt = stoi(command.substr(2));

			if (command[0] == 'U') {
				while (cnt--) {
					now = now->prev;
				}
			}
			else {
				while (cnt--) {
					now = now->next;
				}
			}
		}
		else if (command[0] == 'C') {
			logs.push(now);

			if (now == head) {
				head = head->next;
				head->prev = nullptr;

				now = head;
			}
			else if (now == tail) {
				tail = tail->prev;
				tail->next = nullptr;

				now = tail;
			}
			//between head and tail
			else {
				now->prev->next = now->next;
				now->next->prev = now->prev;

				now = now->next;

			}
		}
		else if (command[0] == 'Z') {
			auto log = logs.top();
			logs.pop();

			if (log->prev == nullptr) {
				head = log;
				head->next->prev = head;
			}
			else if (log->next == nullptr) {
				tail = log;
				tail->prev->next = tail;
			}

			else {
				log->prev->next = log;
				log->next->prev = log;
			}
		}
	}

	now = head;
	while (now) {
		answer[now->val] = 'O';
		now = now->next;
	}

	return answer;
}

int main()
{
	//cout << solution(8, 2, { "D 2", "C", "U 3","C","D 4","C" });
	cout << solution(8, 2, { "D 2", "C", "U 3","C","D 4", "C", "U 2","Z","Z","U 1","C" });
}