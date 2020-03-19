#include <iostream>
#include <algorithm>
#define endl '\n'

using namespace std;

int seq[1001];
int dp[1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, ans;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> seq[i];

	dp[0] = 1;
	ans = 1;

	for (int i = 1; i < n; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (seq[i] > seq[j] && dp[i] <= dp[j])
			{
				dp[i] = dp[j] + 1;
				ans = max(ans, dp[i]);
			}
		}
	}

	cout << ans << endl;

	return 0;
}