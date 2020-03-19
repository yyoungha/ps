#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#define endl '\n'
using namespace std;

vector<pair<int, string>> v;

bool compare(pair<int, string> a, pair<int, string> b)
{
	return a.first < b.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int age;
	string name;
	for (int i = 0; i < n; i++)
	{
		cin >> age >> name;
		v.push_back({ age, name });
	}

	std::stable_sort(v.begin(), v.end(), compare);

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i].first << " " << v[i].second << endl;
	}

	return 0;
}