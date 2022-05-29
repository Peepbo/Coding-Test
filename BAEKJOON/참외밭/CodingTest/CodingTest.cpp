#include <iostream>
#include <vector>

using namespace std;

class Line
{
public:
	Line(int Idx, int Dir, int Len, Line* Prev) :
		Index{ Idx }, Direction{ Dir }, Length{ Len }, NextLine{ nullptr }, PrevLine{ Prev } {}

	int Index, Direction, Length;
	Line* NextLine, * PrevLine;
};

class Square
{
public:
	Square() : Head{ nullptr }, Tail{ nullptr } {}
	~Square()
	{
		Line* DestPtr{ Head };

		while (DestPtr != Tail)
		{
			Line* DeletePtr{ DestPtr };
			if (DestPtr->NextLine != nullptr)
			{
				DestPtr = DestPtr->NextLine;
			}

			delete DeletePtr;
		}
		delete Tail;

		Head = Tail = nullptr;
	}

	void AddLine(int Idx, int Dir, int Len)
	{
		if (Tail == nullptr)
		{
			Head = new Line(Idx, Dir, Len, nullptr);
			Tail = Head;
		}
		else
		{
			Tail->NextLine = new Line(Idx, Dir, Len, Tail);
			Tail = Tail->NextLine;
		}

		DirCount[Dir]++;
	}
	void MakeSquare()
	{
		Tail->NextLine = Head;
		Head->PrevLine = Tail;
	}
	int GetArea()
	{
		vector<int> SingleDir;
		for (int i = 1; i <= 4; i++)
		{
			if (DirCount[i] == 1)
			{
				SingleDir.emplace_back(i);
			}
		}
		Line* Line1 = FindLine(SingleDir[0]);
		Line* Line2 = FindLine(SingleDir[1]);

		if (Line1 == nullptr || Line2 == nullptr)
		{
			return 0;
		}
		const int FullArea{ Line1->Length * Line2->Length };

		const bool bUseNextLine1{ Line1->NextLine->Index != Line2->Index };
		const bool bUseNextLine2{ !bUseNextLine1 };

		Line* EmptySpaceLine1 = (bUseNextLine1 ?
			Line1->NextLine->NextLine :
			Line1->PrevLine->PrevLine
			);
		Line* EmptySpaceLine2 = (bUseNextLine2 ?
			Line2->NextLine->NextLine :
			Line2->PrevLine->PrevLine
			);

		const int EmptyArea{ EmptySpaceLine1->Length * EmptySpaceLine2->Length };

		return FullArea - EmptyArea;
	}

private:
	Line* FindLine(int Dir)
	{
		if (Head == nullptr)
		{
			return nullptr;
		}

		Line* FinderPtr{ Head };
		while (FinderPtr != nullptr)
		{
			if (FinderPtr->Direction == Dir)
			{
				return FinderPtr;
			}
			FinderPtr = FinderPtr->NextLine;
		}
	}
private:
	Line* Head, * Tail;
	int DirCount[5]{ 0 };
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Square MySquare;
	int K, Dir, Len;

	cin >> K;

	for (int i = 0; i < 6; i++)
	{
		cin >> Dir >> Len;

		MySquare.AddLine(i, Dir, Len);
	}
	MySquare.MakeSquare();
	cout << MySquare.GetArea() * K;

	return 0;
}