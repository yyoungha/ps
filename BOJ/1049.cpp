#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;

	int pkg_low = 1000, each_low = 1000;
	int pkg_price, each_price;

	for (int brand = 0; brand < m; brand++)
	{
		cin >> pkg_price >> each_price;
		pkg_low = min(pkg_price, pkg_low);
		each_low = min(each_price, each_low);
	}

	int pkg_total = (((n - 1) / 6) + 1) * pkg_low;
	int each_total = n * each_low;
	int combined_total = ((n - 1) / 6) * pkg_low + (n - ((n - 1) / 6) * 6) * each_low;
	int ans = min(pkg_total, min(each_total, combined_total));

	cout << ans;

	return 0;
}