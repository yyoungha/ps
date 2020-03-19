#include <iostream>
#include <cmath>

using namespace std;

bool contains666(int num)
{
	while (num > 100)
	{
		if (num == 666 || num % 1000 == 666) return true;
		num /= 10;
	}
	return false;
}

int main()
{
	long long number = 666;
	int n, cnt = 1;
	cin >> n;

	while( cnt < n )
	{
		number++;
		if (contains666(number)) cnt++;
	}

	cout << number << endl;
	return 0;
}