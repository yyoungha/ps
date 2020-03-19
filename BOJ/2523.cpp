#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= 2 * n - 1; i++)
	{
		int j;

		if (i <= n) j = i;
		else j = 2 * n - i;

		while (j > 0) {
			cout << "*";
			j--;
		}
		cout << endl;
	}

	return 0;
}