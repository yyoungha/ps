#include <iostream>
#define endl '\n'

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	for(int i = 2; i <= n; i++)
		while (n % i == 0)
		{
			n /= i;
			cout << i << endl;
		}

	return 0;
}