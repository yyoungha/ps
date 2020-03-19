#include <iostream>
#define ll long long
#define endl '\n'

using namespace std;

ll arr[101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, t;
	arr[1] = 1; arr[2] = 1; arr[3] = 1;
	arr[4] = 2; arr[5] = 2;
	cin >> t;

	while (t--)
	{
		cin >> n;

		for (int i = 6; i <= n; i++)
			arr[i] = arr[i - 1] + arr[i - 5];

		cout << arr[n] << endl;
	}
	return 0;
}