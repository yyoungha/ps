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

	int n, num;
	vector<int> v, d;
	cin >> n;

	for(int i = 0; i < n; i++)
	{
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());

	int ans = 0;
	d.push_back(v[0]);
	for (int i = 1; i < n; i++)
	{
		d.push_back(d[i-1] + v[i]);
	}
	for (int i = 0; i < n; i++)
		ans += d[i];

	cout << ans << endl;

	return 0;
}