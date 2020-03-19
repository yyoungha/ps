#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#define endl '\n'
using namespace std;

vector<pair<int, string>> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	string s;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		v.push_back(make_pair(s.size(), s));
	}

	std::sort(v.begin(), v.end());

	cout << v[0].second << endl;
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i].second == v[i - 1].second) continue;
		cout << v[i].second << endl;
	}

	return 0;
}