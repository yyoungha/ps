#include <iostream>

using namespace std;

int main()
{
	int x, y, quadrant;
	cin >> x >> y;
	if (y > 0)
	{
		if (x > 0) quadrant = 1;
		else quadrant = 2;
	}
	else
	{
		if (x > 0) quadrant = 4;
		else quadrant = 3;
	}
	cout << quadrant << endl;

	return 0;
}