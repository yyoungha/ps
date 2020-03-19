#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define endl '\n'

using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.second == b.second)
		return a.first > b.first;
	return a.second > b.second;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<pair<int, int>> v;

	int start, end, count = 0;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> start >> end;
		v.push_back(make_pair(start, end));
	}

	sort(v.begin(), v.end(), cmp);

	int finish = 0;
	for (int i = 0; i < n; i++)
	{
		start = v.back().first;
		end = v.back().second;
		v.pop_back();

		if (finish > start)
			continue;

		count++;
		finish = end;
	}

	cout << count;
	return 0;
}