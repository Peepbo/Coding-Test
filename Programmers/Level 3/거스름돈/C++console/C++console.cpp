//#include <iostream>
//#include <time.h>
//#include <vector>
//
//using namespace std;
//
//vector<int> puzzleNum;
//int* Input = new int[3];
//int strikeCnt = 0;
//int ballCnt = 0;
//
//void RandomNumber()
//{
//	vector<int> _numbers;
//	for (int i = 0; i < 10; i++) _numbers.push_back(i);
//
//	int count = 0;
//	while (count < 3)
//	{
//		int _ran = rand() % _numbers.size();
//		puzzleNum.push_back(_numbers[_ran]);
//
//		_numbers.erase(_numbers.begin() + _ran);
//
//		count++;
//	}
//}
//
//bool Exception(int idx)
//{
//	if (Input[idx] < 0 || Input[idx] > 9)
//	{
//		cout << "수가 올바르지 않습니다!" << "\n\n";
//
//		return true;
//	}
//
//	if (idx > 0)
//	{
//		bool same = false;
//		for (int j = 0; j < idx; j++)
//		{
//			if (Input[j] == Input[idx])
//			{
//				same = true;
//				break;
//			}
//		}
//
//		if (same)
//		{
//			cout << "같은 수를 입력했습니다!" << "\n\n";
//
//			return true;
//		}
//	}
//
//	return false;
//}
//
//bool CheckClear()
//{
//	cout << '\n';
//
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			if (i == j)
//			{
//				if (puzzleNum[i] == Input[j]) strikeCnt++;
//			}
//
//			else
//			{
//				if (puzzleNum[i] == Input[j]) ballCnt++;
//			}
//		}
//	}
//
//	cout << "strike cnt : " << strikeCnt << '\n';
//	cout << "ball cnt : " << ballCnt << '\n';
//
//	if (strikeCnt == 3) return true;
//
//	return false;
//}
//
//void ResetCnt()
//{
//	strikeCnt = 0; ballCnt = 0;
//	for (int i = 0; i < 3; i++)Input[i] = 0;
//}
//
//int main()
//{
//	srand(time(NULL));
//
//	RandomNumber();
//
//	cout << "숫자야구를 시작하겠습니다\n\n";
//
//	while (strikeCnt != 3)
//	{
//		cout << "intput : ";
//
//		bool inputReset = false;
//		for (int i = 0; i < 3;)
//		{
//			cin >> Input[i];
//
//			if (Exception(i))
//			{
//				inputReset = true;
//
//				break;
//			}
//
//			else i++;
//		}
//
//		if (inputReset)continue;
//
//		if (CheckClear()) break;
//
//		else ResetCnt();
//
//		cout << "\n\n";
//	}
//
//	return 0;
//}