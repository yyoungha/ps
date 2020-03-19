#include <iostream>
#include <utility>
#include <algorithm>
#define endl '\n'

using namespace std;

int arr[10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, num;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> num;
		arr[num]++;
	}

	int cnt = 0;
	for (int i = 1; i < 10001; i++)
	{
		while (arr[i]--)
		{
			cout << i << endl;
			cnt++;
		}
		if (cnt == n) break;
	}

	return 0;
}