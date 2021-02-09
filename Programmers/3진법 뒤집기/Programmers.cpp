#include <algorithm>
#include <iostream>
//#include <vector>
#include <math.h>
#include <stack>

using namespace std;

#pragma region  Stack
void reverseStack(stack<int>& stk)
{
	stack<int> tempStack;
	int save;
	while (stk.empty() == false)
	{
		tempStack.push(stk.top());
		stk.pop();
	}

	stk = tempStack;
	return;
}

int solution(int n)
{
	int answer = 0;
	stack<int> ternarySystem;

	while (n > 0)
	{
		ternarySystem.push(n % 3);
		n /= 3;
	}

	reverseStack(ternarySystem);

	int order = 0;
	int size = ternarySystem.size();
	while (ternarySystem.empty() == false)
	{
		answer += ternarySystem.top() * pow(3, (size - 1) - order);
		ternarySystem.pop();
		order++;
	}

	return answer;
}
#pragma endregion

#pragma region Vector
//int solution(int n) {
//	int answer = 0;
//	vector<int> ternarySystem;
//
//	while (n > 0)
//	{
//		ternarySystem.push_back(n % 3);
//		n /= 3;
//	}
//
//	reverse(ternarySystem.begin(), ternarySystem.end()); // ternarySystem
//
//	reverse(ternarySystem.begin(), ternarySystem.end()); // ternarySystem reverse
//
//	int size = ternarySystem.size();
//	for (int i = 0; i < size; i++)
//	{
//		answer += ternarySystem[(size - 1) - i] * pow(3, i);
//	}
//
//	return answer;
//}
#pragma endregion



int main()
{
	cout << solution(45);

	return 0;
}