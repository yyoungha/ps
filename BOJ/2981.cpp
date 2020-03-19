#include <iostream>
#include <cmath>
#include <algorithm>
#define endl '\n'

using namespace std;
int arr[100];

int gcd(int a, int b)
{
	if (a % b == 0) { return b;	}
	return gcd(b, a % b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, g;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	g = arr[1] - arr[0];
	for (int i = 2; i < n; i++)
		g = gcd(arr[i] - arr[i - 1], g);

	for(int i = 2; i <= g/2; i++)
		if (g % i == 0)
		{
			cout << i << " ";
		}
	cout << g;

	return 0;
}