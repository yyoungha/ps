#include <iostream>
#include <string>
using namespace std;

int arr[10];

void selectionSort(int* list, const int n)
{
	int i, j, indexMin, temp;

	for (i = 0; i < n - 1; i++)
	{
		indexMin = i;
		for (j = i + 1; j < n; j++)
		{
			if (list[j] > list[indexMin])
			{
				indexMin = j;
			}
		}
		temp = list[indexMin];
		list[indexMin] = list[i];
		list[i] = temp;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++)
		arr[i] = s[i] - '0';

	selectionSort(arr, s.size());

	for (int i = 0; i < s.size(); i++)
		cout << arr[i];

	return 0;
}