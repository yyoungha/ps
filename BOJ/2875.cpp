#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k, team, left;
	cin >> n >> m >> k;

	if (n >= 2 * m) team = m;
	else team = n / 2;

	left = n + m - (team * 3);

	k -= left;
	if ( k > 0 ) team -= ceil(k / 3.0);

	cout << team;

	return 0;
}