#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define endl '\n'

int coin[5] = { 500, 100, 50, 10, 5 };

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int price, r, cnt = 0, ans = 0;
	cin >> price;

	r = 1000 - price;
	for (int i = 0; i < 5; i++)
	{
		cnt = r / coin[i];
		r -= coin[i] * (cnt);
		ans += cnt;
	}
	ans += r;

	cout << ans << endl;

	return 0;
}