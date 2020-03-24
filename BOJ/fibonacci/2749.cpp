#include <iostream>

using namespace std;

const int period = 1500000;
int arr[period] = { 0, 1 };

void fib(long long n)
{
	for (int i = 2; i < period; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2]) % 1000000;
	}
}

int main()
{
	long long n;
	cin >> n;

	fib(n);

	cout << arr[n%period] << endl;

	return 0;
}