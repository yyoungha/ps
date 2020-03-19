#include <iostream>
#include <algorithm>
#define endl '\n'

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, num, mn = 1000000, mx = 2;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		mn = min(mn, num);
		mx = max(mx, num);
	}

	cout << mn * mx << endl;


	return 0;
}