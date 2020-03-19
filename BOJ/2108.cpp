#include <iostream>
#include <algorithm>
#include <cmath>
#define endl '\n'

using namespace std;

const int MAX_SIZE = 8001;
int arr[MAX_SIZE];
int num[500000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,
		sum = 0, mx = -4000, mn = 4000, mx_count = 0,
		median, mode;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
		sum += num[i];
		arr[num[i] + 4000]++;
		if (mx_count < arr[num[i] + 4000]) mx_count = arr[num[i] + 4000];
		if (i == n / 2) median = num[i];
		mx = max(mx, num[i]);
		mn = min(mn, num[i]);
	}
	// average
	cout << round(sum / (float)n) << endl;
	// median
	sort(num, num + n);
	cout << num[n / 2] << endl;
	// mode
	bool flag = true;
	for (int i = 0; i < MAX_SIZE; i++)
		if (arr[i] == mx_count)
		{
			if (flag)
			{
				mode = i - 4000;
				flag = false;
			}
			else
			{
				mode = i - 4000;
				break;
			}
		}
	cout << mode << endl;
	// range
	cout << mx - mn << endl;


	return 0;
}