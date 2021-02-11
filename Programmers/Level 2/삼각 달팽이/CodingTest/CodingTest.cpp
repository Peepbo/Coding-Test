#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class TYPE
{
    DOWN,
    RIGHT,
    UP
};

void changeType(TYPE& type)
{
    if (type != TYPE::UP)
        type = TYPE((int)type + 1);
    else
        type = TYPE::DOWN;
}

class Node
{
public:
    int order;
    int num;

    Node(int _order, int _num)
    {
        order = _order;
        num = _num;
    }

    bool operator < (Node& node)
    {
        return this->order < node.order;
    }
};

vector<int> solution(int n) {
    vector<int> answer;

    vector<Node>* test = new vector<Node>[n];
    TYPE type = TYPE::DOWN;

    int len = n;
    int start = 0, end = 0, num = 1;
    int downCount = 0, upCount = 0;
    int count, idx, plus;
    while (n >= 0)
    {
        switch (type)
        {
        case TYPE::DOWN:
            count = n;
            idx = start;
            while (count > 0)
            {
                test[idx].push_back({ downCount, num });

                idx++;
                num++;
                count--;
            }

            start = idx - 1;
            downCount++;
            break;
        case TYPE::RIGHT:
            count = n;
            plus = 0;
            while (count > 0)
            {
                test[start].push_back({ downCount + plus,num });

                plus++;
                num++;
                count--;
            }
            start--;
            end++;
            break;
        case TYPE::UP:
            count = n;
            idx = start;
            while (count > 0)
            {
                test[idx].push_back({ 1000 - upCount,num });

                num++;
                idx--;
                count--;
            }

            start = end + 1 + upCount;

            upCount++;
            break;
        }

        changeType(type);
        n--;
    }

    for (int i = 0; i < len; i++)
    {
        sort(test[i].begin(), test[i].end());
        for (int j = 0; j < test[i].size(); j++)
        {
            answer.push_back(test[i][j].num);
        }
    }

    return answer;
}

int main()
{
    vector<int> output = solution(20);
    for (int i = 0; i < output.size(); i++)cout << output[i] << ',';
	return 0;
}