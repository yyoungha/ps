#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;

	int ans = 50, curr;
	for (int i = 0; i <= b.length() - a.length(); i++)
	{
		curr = 0;
		for (int j = 0; j < a.length(); j++)
			if (b[i + j] != a[j]) curr++;

		ans = min(curr, ans);
	}

	cout << ans;

	return 0;
}