#include <iostream>
#include <utility>
#include <queue>

using namespace std;

const int INT_MAX = 2147483647;
const int SIZE = 22;

int n = 0;
int cnt = 1;
int shark_size = 2;
int shark_x, shark_y;
int map[SIZE][SIZE];
int visited[SIZE][SIZE] = { 0, };

// »ó, ÁÂ, ÇÏ, ¿ì ¼øÀ¸·Î Å½»ö
int move_x[4] = { -1, 0, 0, 1 };
int move_y[4] = { 0, -1, 1, 0 };

int solve(int sx, int sy)
{
	int fish = 0;
	int status = 1;
	int sum = 0;

	while (status)
	{
		status = 0;

		if (fish == shark_size)
		{
			shark_size++;
			fish = 0;
		}

		priority_queue < pair<int, pair <int, int>> > q;
		q.push(make_pair(0, make_pair(-sx, -sy)));
		visited[sx][sy] = cnt;

		while (!q.empty())
		{
			int s = -q.top().first;
			int x = -q.top().second.first;
			int y = -q.top().second.second;
			q.pop();

			if (map[x][y] != 0 && map[x][y] < shark_size) {
				fish++;
				status = 1;
				sx = x;
				sy = y;
				sum += s;
				map[x][y] = 0;
				break;
			}

			for (int i = 0; i < 4; i++) {
				int ns = s + 1;
				int nx = x + move_x[i];
				int ny = y + move_y[i];

				if (visited[nx][ny] != cnt && map[nx][ny] <= shark_size) {
					visited[nx][ny] = cnt;
					q.push(make_pair(-ns, make_pair(-nx, -ny)));
				}
			}
		}

		cnt++;
	}

	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			map[i][j] = INT_MAX;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				shark_x = i;
				shark_y = j;
				map[i][j] = 0;
			}
		}
	}

	cout << solve(shark_x, shark_y) << endl;


	return 0;
}