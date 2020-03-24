#include <iostream>

using namespace std;

int arr[46];

int fib(int n)
{
	if (n <= 1) return 1;

	for (int i = 3; i <= n; i++)
		arr[i] = arr[i - 1] + arr[i - 2];

	return arr[n];
}

int main()
{
	int n;
	cin >> n;

	arr[0] = 0;
	arr[2] = arr[1] = 1;
	cout << fib(n);

	return 0;
}