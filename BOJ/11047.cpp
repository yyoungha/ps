#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int> v;
	int m;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		v.push_back(m);
	}

	int coin, count, ans = 0;	
	while (k != 0) {
		coin = v.back();
		v.pop_back();

		if (k - coin < 0) continue;
		count = k / coin;
		ans += count;
		k -= count * coin;
	}

	cout << ans;

	return 0;
}