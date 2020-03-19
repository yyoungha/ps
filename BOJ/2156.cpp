#include <iostream>
#define endl '\n'

using namespace std;

int wine[10001] = { 0, };
int dp[10001];

// i번째 포도주에서 생각할 수 있는 경우의 수
// 1) i-1번째도 마시고 i-2번째 마심 => i번째 와인 마시기 불가능 dp[i - 1]
// 2) i-1번째 마시고 i-2번째 안마심 => 가능 dp[i - 3] + wine[i - 1] + wine[i]
// 3) i-1번째 안마시고 i-2번째 마심 => 가능 dp[i - 2] + wine[i]
// 4) i-1번째 안마시고 i-2번째 안마심 => 가능하지만 1)과 2)를 계산하면서 고려되는 경우임.

int max(int a, int b, int c)
{
	if (a > b)
	{
		if (a > c) return a;
	}
	else if (b > c) return b;
	return c;	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> wine[i];

	if (n <= 2)
	{
		cout << wine[1] + wine[2] << endl;
		return 0;
	}

	dp[1] = wine[1];
	dp[2] = wine[2] + wine[1];
	for (int i = 3; i <= n; i++)
		dp[i] = max(dp[i - 3] + wine[i - 1] + wine[i], dp[i - 1], dp[i - 2] + wine[i]);

	cout << dp[n] << endl;

	return 0;
}