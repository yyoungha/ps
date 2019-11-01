#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string board[51];
int wb[51][51];

void repaint(int n, int m)
{
	for (int y = 0; y < n; y++)
		for (int x = 0; x < m; x++)
		{
			if ( (y + x) % 2 == 0)
			{
				if (board[y][x] != 'W')
					wb[y][x]++;
			}
			else if (board[y][x] != 'B')
				wb[y][x]++;
		}
}

int solve(int ystart, int xstart, int size)
{
	int w = 0;
	// check wb
	for (int y = 0; y < size; y++)
		for (int x = 0; x < size; x++)
		{
			if (wb[ystart + y][xstart + x]) w++;
		}

	return std::min(w, size * size - w);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> board[i];

	// 1. repaint
	repaint(n, m);

	// 2. count each 8x8 square
	int ans = 2100000000;
	for (int y = 0; y + 7 < n; y++)
		for (int x = 0; x + 7 < m; x++)
			ans = std::min(ans, solve(y, x, 8));

	cout << ans << endl;

	return 0;
}