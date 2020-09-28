#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <cstring>
using namespace std;

int n, m;
int a[50][50];
int visited[50][50];
int mx[4] = { 0, -1, 0, 1 };
int my[4] = { -1, 0, 1, 0 };

int bfs(int x, int y, int cnt)
{
	vector<pair<int, int>> v;
	queue<pair<int, int>> q;
	v.push_back({ x, y });
	q.push({ x, y });
	visited[x][y] = cnt + 1;

	int area = 1;
	while (!q.empty()) {
		tie(x, y) = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			if (!(a[x][y] & (1 << k))) {
				int nx = x + mx[k];
				int ny = y + my[k];

				if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
				if (visited[nx][ny]) continue;
				v.push_back({ nx, ny });
				q.push({ nx, ny });
				visited[nx][ny] = cnt + 1;
				area++;
			}
		}
	}

	for (auto& p : v) 
		a[p.first][p.second] = area;
	
	return area;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];

	int cnt = 0, al = 1;
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (!visited[i][j]) {
				int temp = bfs(i, j, cnt);
				if (al < temp) al = temp;
				cnt++;
			}

	int bl = 1;
	int temp;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			if (j + 1 < n && visited[i][j] != visited[i][j + 1]) {
				temp = a[i][j] + a[i][j + 1];
				if (bl < temp) bl = temp;
			}
			if (i + 1 < m && visited[i][j] != visited[i + 1][j]) {
				temp = a[i][j] + a[i + 1][j];
				if (bl < temp) bl = temp;
			}
		}

	cout << cnt << endl;
	cout << al << endl;
	cout << bl << endl;

	return 0;
}
