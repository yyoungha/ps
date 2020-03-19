#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int k;
	cin >> k;

	int high[10] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
		low[10] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
	char symbol[10];
	vector<int> greater, less;

	for (int i = 1; i <= k; i++)
	{
		cin >> symbol[i];
		if (symbol[i] == '>') greater.push_back(i);
		else less.push_back(i);
	}

	// high
	int p, num = 9;
	symbol[0] = '>';
	for (int i = 0; i < greater.size(); i++)
	{
		p = greater[i];
		do {
			high[p - 1] = num--;
			p--;
		} while (symbol[p] != '>');
	}

	for (int i = k; high[i] == -1; i--)
		high[i] = num--;

	// low
	num = 0;
	symbol[0] = '<';
	for (int i = 0; i < less.size(); i++)
	{
		p = less[i];
		do {
			low[p - 1] = num++;
			p--;
		} while (symbol[p] != '<');
	}

	for(int i = k; low[i] == -1; i--)
		low[i] = num++;

	// print
	for (int i = 0; i <= k; i++)
		cout << high[i];
	cout << endl;

	for (int i = 0; i <= k; i++)
		cout << low[i];
	cout << endl;

	return 0;
}