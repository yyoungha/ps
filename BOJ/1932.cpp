#include <iostream>
#include <algorithm>
#define endl '\n'

using namespace std;

int tri[501][501];
int sum[501][501];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, ans = 0;
	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			cin >> tri[i][j];

	sum[1][1] = tri[1][1];
	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= i; j++)
		{
			sum[i][j] = max(sum[i - 1][j - 1], sum[i - 1][j]) + tri[i][j];
		}
		
	for (int i = 1; i <= n; i++)
		ans = max(ans, sum[n][i]);

	cout << ans << endl;
			
	return 0;
}