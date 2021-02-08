#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
	string answer = "";

	for (int i = 0; i < new_id.size(); i++)
	{
		new_id[i] = tolower(new_id[i]);
	}

	for (int i = 0; i < new_id.size();)
	{
		int ascii = (int)new_id[i];
		if ((ascii >= 'a' && ascii <= 'z') ||
			(ascii >= '0' && ascii <= '9') ||
			ascii == '-' || ascii == '_' ||
			ascii == '.')
		{
			i++;
			continue;
		}

		new_id.erase(new_id.begin() + i);
	}

	int idx = new_id.find("..");
	while (idx != -1)
	{
		new_id.erase(new_id.begin() + idx);
		idx = new_id.find("..");
	}

	if (new_id.front() == '.')new_id.erase(new_id.begin());
	if (new_id.back() == '.')new_id.erase(new_id.end()-1);

	if (new_id.empty())new_id = "a";

	if (new_id.size() >= 16)new_id.erase(new_id.begin() + 15, new_id.end());

	if (new_id.back() == '.')new_id.erase(new_id.end()-1);

	while (new_id.size() <= 2)
		new_id += new_id.back();

	answer = new_id;

	return answer;
}

int main()
{
	solution("...!@BaT#*..y.abcdefghijklm");

	return 0;
}