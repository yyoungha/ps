#include <iostream>

using namespace std;

int solve(int m)
{
	int p = 1,
		pp = 1,
		c,
		ans = 0;

	do
	{
		c = (p + pp) % m;
		pp = p;
		p = c;
		ans++;
	} while (!(p == 1 && pp == 1));

	return ans;
}

int main()
{
	int p, n, m;
	cin >> p;

	while (p--)
	{
		cin >> n >> m;
		cout << n << " " << solve(m) << endl;
	}
	return 0;
}