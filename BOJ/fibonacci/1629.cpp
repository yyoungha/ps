#include <iostream>

using namespace std;

long long pow(int a, int b, int c)
{
	if (b != 0) {
		long long val = pow(a, b / 2, c);
		if (b % 2 == 0) return val * val % c;
		else return val * val % c * a % c;
	}

	return 1;
}
int main()
{
	int a, b, c;
	cin >> a >> b >> c;

	cout << pow(a, b, c) << endl;

	return 0;
}