#include <vector>
#include <iostream>

using namespace std;

enum class sortCondition
{
	Ascending, Descending
};

void printVector(const vector<int>& v)
{
	for (const int& temp : v)
		cout << temp << ' ';
	cout << "\n\n";
}

void insertionSort(vector<int> v, const sortCondition& c)
{
	int cycle = v.size();

	printVector(v);

	switch (c)
	{
	case sortCondition::Ascending:
		for (int i = 1; i < cycle; i++)
		{
			cout << i << "회전\n";

			for (int j = 0; j < i; j++)
			{
				if (v[i] < v[j])
					swap(v[i], v[j]);
			}

			printVector(v);
		}

		break;
	case sortCondition::Descending:
		for (int i = 1; i < cycle; i++)
		{
			cout << i << "회전\n";

			for (int j = 0; j < i; j++)
			{
				if (v[i] > v[j])
					swap(v[i], v[j]);
			}

			printVector(v);
		}

		break;
	}
}

void selectionSort(vector<int> v)
{
	int cycle = v.size();

	printVector(v);

	for (int i = 0; i < cycle - 1; i++)
	{
		cout << i + 1 << "회전\n\n";

		for (int j = i + 1; j < cycle; j++)
		{
			if (v[i] > v[j])
				swap(v[i], v[j]);
		}

		printVector(v);
	}
}

void bubbleSort(vector<int> v)
{
	int cycle = v.size();

	printVector(v);

	for (int i = 0; i < cycle - 1; i++)
	{
		cout << i + 1 << "회전\n";

		for (int j = 0; j < (cycle - 1) - i; j++)
		{
			if (v[j] > v[j + 1])
				swap(v[j], v[j + 1]);
		}

		printVector(v);
	}
}

void quickSort(vector<int>& v, const int& start, const int& end)
{
	if (start >= end) return;

	int pivot = start, i = pivot + 1, j = end;

	while (i <= j)
	{
		while (i <= end && v[i] <= v[pivot])i++;
		while (j > start && v[j] >= v[pivot])j--;

		if (i > j)
		{
			swap(v[pivot], v[j]);
		}
		else
		{
			swap(v[i], v[j]);
		}
	}

	printVector(v);

	quickSort(v, start, j - 1);
	quickSort(v, j + 1, end);
}

int main()
{
	insertionSort({ 8,5,6,2,4 }, sortCondition::Ascending);
	//selectionSort({ 8,5,6,2,4 });
	//bubbleSort({ 8,5,6,2,4 });
	//vector<int> v{ 8,5,6,2,4 };
	//printVector(v);
	//quickSort(v, 0, v.size() - 1);
}