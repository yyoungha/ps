#include <iostream>

using namespace std;

int A[51][51];
int B[51][51];

void flip(int y, int x)
{
	for (int i = y; i < y + 3; i++)
		for (int j = x; j < x + 3; j++)
			A[i][j] = !A[i][j];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, count = 0;
	string tmp;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		for (int j = 0; j < m; j++)
			A[i][j] = tmp.at(j) - '0';
	}

	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		for (int j = 0; j < m; j++)
			B[i][j] = tmp.at(j) - '0';
	}

	if (n < 3 || m < 3)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (A[i][j] != B[i][j])
				{
					cout << -1;
					return 0;
				}
	}
	else
	{
		int i, j;
		for (i = 0; i < n - 2; i++)
		{
			for (j = 0; j < m - 2; j++)
				if (A[i][j] != B[i][j])
				{
					flip(i, j);
					count++;
				}

			if (A[i][j] != B[i][j] || A[i][j + 1] != B[i][j + 1])
			{
				cout << -1;
				return 0;
			}
		}

		for (int j = 0; j < m; j++)
		{
			if (A[i][j] != B[i][j] || A[i + 1][j] != B[i + 1][j])
			{
				cout << -1;
				return 0;
			}
		}
	}
	cout << count;
	return 0;
}