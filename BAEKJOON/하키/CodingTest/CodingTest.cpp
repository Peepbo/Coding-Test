#include <iostream>
#include <math.h>

using namespace std;

struct Point
{
	int x, y;
};

class Range
{
public:
	Range(int min, int max) :
		Min{ min }, Max{ max }{}
	/* 반환 값
	-1 : 범위 값보다 작음
	0  : 범위안에 듬
	1  : 범위보다 큼 
	*/
	int CheckRange(int Value)
	{
		if (Value < Min)
		{
			return -1;
		}
		else if (Max < Value)
		{
			return 1;
		}
		return 0;
	}
private:
	int Min, Max;
};

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int W, H, X, Y, P;
	int Count = 0, RangeValue;
	float R;
	cin >> W >> H >> X >> Y >> P;

	Range RangeX(X, X + W);
	Range RangeY(Y, Y + H);
	R = H / 2;

	Point InputPoint;
	while (P--)
	{
		cin >> InputPoint.x >> InputPoint.y;
		
		if (RangeY.CheckRange(InputPoint.y) != 0)
		{
			continue;
		}

		RangeValue = RangeX.CheckRange(InputPoint.x);
		Point DatumPoint{ 0,0 };
		switch (RangeValue)
		{
		case 0:
			Count++;
			continue;
		case -1:
			DatumPoint = { X, Y + (int)R };
			break;
		case 1:
			DatumPoint = { X + W, Y + (int)R };
			break;
		}

		const int TempX = DatumPoint.x - InputPoint.x;
		const int TempY = DatumPoint.y - InputPoint.y;
		
		const float Distance = sqrt(pow(TempX,2) + pow(TempY,2));
		if (Distance <= R)
		{
			Count++;
		}
	}

	cout << Count;
	return 0;
}