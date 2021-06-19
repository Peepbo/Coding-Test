#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
	string answer = "";
	int day = b;
	int Imonth[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	string Sday[12] = { "FRI","SAT","SUN","MON","TUE","WED","THU" };

	for (int i = 0; i < a - 1; i++)
	{
		day += Imonth[i];
	}
	day -= 1;
	answer = Sday[day % 7];
	return answer;
}

int main()
{

}