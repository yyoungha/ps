#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int INT_INF = 2147483647;
const int MAX_SIZE = 201;
const int MAX_SIZE_2X = MAX_SIZE * 2;
const int WHITE = 0;
const int BLACK = 1;
const int GRAY = 2;

vector<int> vertex[MAX_SIZE_2X];
int parent[MAX_SIZE_2X];
int color[MAX_SIZE_2X];
int capacity[MAX_SIZE_2X][MAX_SIZE_2X] = { 0, };
int flow[MAX_SIZE_2X][MAX_SIZE_2X] = { 0, };
int n, maxflow = 0;

void bfs(int source, int sink)
{
	queue<int> q;
	int u;

	color[source] = GRAY;
	q.push(source);

	while (!q.empty() && parent[sink] == -1)
	{
		u = q.front();
		q.pop();

		for (auto v : vertex[u])
		{
			if (color[v] == WHITE && capacity[u][v] - flow[u][v] > 0)
			{
				color[v] = GRAY;
				parent[v] = u;
				q.push(v);
			}
		}
		color[u] = BLACK;
	}
}

int ctoi(char c)
{
	if (c >= 'A' && c <= 'Z')
		return c - 'A';
	return c - 'A' - 6;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	char fromChar, toChar;
	int from, to, c;
	int source = ctoi('A'),
		sink = ctoi('Z');

	// construct flow network
	for (int i = 0; i < n; i++)
	{
		cin >> fromChar >> toChar >> c;
		from = ctoi(fromChar);
		to = ctoi(toChar);

		// add edge
		vertex[from].push_back(to);
		vertex[to].push_back(from);
		capacity[from][to] += c;
		capacity[to][from] += c;
	}

	// Edmonds-Karp
	while (1)
	{
		fill(parent, parent + MAX_SIZE_2X, -1);
		fill(color, color + MAX_SIZE_2X, WHITE);

		bfs(source, sink);

		// no augmenting path then exit
		if (parent[sink] == -1) break;

		// find minimum residual capacity of the augmenting path
		int residualCapacity = INT_INF,
			to,
			from = sink;

		while (from > source)
		{
			to = from;
			from = parent[from];
			residualCapacity = std::min(residualCapacity, capacity[from][to] - flow[from][to]);
		}

		// update flow
		from = sink;
		while (from > source)
		{
			to = from;
			from = parent[from];
			flow[from][to] += residualCapacity;
			flow[to][from] -= residualCapacity;
		}

		maxflow += residualCapacity;
	}

	cout << maxflow << endl;

	return 0;
}