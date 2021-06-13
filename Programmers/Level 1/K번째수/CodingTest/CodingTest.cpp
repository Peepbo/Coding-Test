#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	vector<int> cul;
	for (int i = 0; i < commands.size(); i++)
	{
		for (int j = commands[i][0] - 1; j < commands[i][1]; j++)
		{
			cul.push_back(array[j]);
		}

		for (int k = 0; k < cul.size() - 1; k++)
		{
			for (int f = 1; f < cul.size() - k; f++)
			{
				if (cul[f - 1] > cul[f])
					swap(cul[f - 1], cul[f]);
			}
		}
		answer.push_back(cul[commands[i][2] - 1]);
		cul.clear();
	}
	return answer;
}

int main()
{

}