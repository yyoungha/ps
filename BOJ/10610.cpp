#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define endl '\n'

using namespace std;

int main()
{
	string op1;
	cin >> op1;

	vector<int> v1;
	vector<int> ans;
	int a, sum = 0;
	for (int i = 0; i < op1.length(); i++)
	{
		a = op1.at(i) - '0';
		v1.push_back(a);
		sum += a;
	}

	sort(v1.begin(), v1.end());

	if (v1.front() != 0 || sum % 3 != 0)
		ans.push_back(-1);
	else
	{
		for (int i = 1; i < op1.length(); i++)
		{
			a = v1.back();
			v1.pop_back();
			ans.push_back(a);
		}
		ans.push_back(0);
	}

	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i];
	}

	return 0;
}