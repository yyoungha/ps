#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#define endl '\n'
using namespace std;

vector<pair<int, int>> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int a, b;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		v.push_back(make_pair(b, a));
	}

	std::sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].second << " " << v[i].first << endl;
	}

	return 0;
}