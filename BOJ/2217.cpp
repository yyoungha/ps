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

	int n, rope, ans = 0;
	vector<int> v;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> rope;
		v.push_back(rope);
	}

	sort(v.begin(), v.end());

	for (int i = 1; i <= n; i++)
	{
		rope = v.back();
		v.pop_back();

		if (i * rope > ans)
			ans = i * rope;
	}

	cout << ans;

	return 0;
}