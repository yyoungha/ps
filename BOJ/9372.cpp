#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	int n, m;
	cin >> t;

	int a, b;
	while (t--)
	{
		cin >> n >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b;
		}
		cout << n - 1 << endl;
	}

	return 0;
}