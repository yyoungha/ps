#include <iostream>
#include <map>
#define ll long long 

using namespace std;

map<ll, ll> d;
const int mod = 1000000007;

ll fib(ll n)
{
	if (n <= 0) return 0;
	else if (n == 1 || n == 2) return 1;
	else if (d.count(n) > 0) return d[n];
	else
	{
		if (n % 2 == 1)
		{
			ll m = (n + 1) / 2;
			ll f1 = fib(m);
			ll f2 = fib(m - 1);
			d[n] = ((f1 * f1) + (f2 * f2)) % mod;
			return d[n];
		}
		else
		{
			ll m = n / 2;
			ll f1 = fib(m - 1);
			ll f2 = fib(m);
			d[n] = ((2 * f1 + f2) * f2) % mod;
			return d[n];
		}
	}

}

ll gcd(ll a, ll b)
{
	ll c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main()
{
	ll n, m;

	cin >> n >> m;
	cout << fib(gcd(n, m)) % mod << endl;
	return 0;
}