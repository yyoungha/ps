#include <iostream>
#include <map>

using namespace std;

map<long long, long long> d;
const int mod = 1000000007;

long long fib(long long n)
{
	if (n <= 0) return 0;
	else if (n == 1 || n == 2) return 1;
	else if (d.count(n) > 0) return d[n];
	else 
	{
		if (n % 2 == 1)
		{
			long long m = (n + 1) / 2;
			long long f1 = fib(m);
			long long f2 = fib(m - 1);

			d[n] = ((f1 * f1) + (f2 * f2)) % mod;
			return d[n];
		}
		else
		{
			long long m = n / 2;
			long long f1 = fib(m - 1);
			long long f2 = fib(m);

			d[n] = ((2 * f1 + f2) * f2) % mod;
			return d[n];
		}
	}
}

int main()
{
	long long n;
	cin >> n;

	if (n % 2 == 1)
		cout << (fib(n) - 1) % mod << endl;
	else
		cout << (fib(n + 1) - 1) % mod << endl;

	return 0;
}