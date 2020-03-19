#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n;
	cin >> t;

	while (t--)
	{
		cin >> n;
		vector<pair<int, int>> v;
		int sca, scb, ans = n;

		for (int i = 0; i < n; i++)
		{
			cin >> sca >> scb;
			v.push_back(make_pair(sca, scb));
		}

		sort(v.begin(), v.end());
		for (int i = n - 1; i > 0; i--)
		{
			scb = v.back().second;
			v.pop_back();

			for (int j = i - 1; j >= 0; j--)
			{
				if (scb > v[j].second)
				{
					ans--;
					break;
				}
			}
		}

		cout << ans << endl;		
	}

	return 0;
}