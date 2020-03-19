#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_SIZE = 51 * 2;

vector<int> graph[MAX_SIZE];
int shark[MAX_SIZE][3];
int flow[MAX_SIZE][MAX_SIZE];
int parent[MAX_SIZE];
int n;

void bfs(int source, int sink)
{
	queue<int> q;
	q.push(source);
	while (!q.empty() && parent[sink] == -1) 
	{
		int u = q.front();
		q.pop();
		for (auto v : graph[u])
			if (flow[u][v] > 0 && parent[v] == -1) 
			{
				q.push(v);
				parent[v] = u;
			}
	}
}

void connect(int from, int to, int c) 
{
	graph[from].push_back(to);
	graph[to].push_back(from);
	flow[from][to] = c;
}

int main() 
{
	int maxflow = 0;

	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 0; j < 3; j++)
			cin >> shark[i][j];

	// source: 0, sink: 2 * n + 1
	int source = 0, sink = 2 * n + 1;
	for (int i = 1; i <= n; i++) 
	{
		// add edge from source to predator(1 ~ n)
		connect(source, i, 2);

		// add edge from prey(n + 1 ~ 2*n) to sink
		connect(i + n, sink, 1);

		// add edge from predator to prey
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (shark[i][0] < shark[j][0] || shark[i][1] < shark[j][1] || shark[i][2] < shark[j][2]) continue;
			if (shark[i][0] == shark[j][0] && shark[i][1] == shark[j][1] && shark[i][2] == shark[j][2] && i > j) continue;
			connect(i, j + n, 1);
		}
	}

	// Ford-Fulkerson
	while (true) 
	{
		fill(parent, parent + MAX_SIZE, -1);
		bfs(source, sink);

		// no augmenting path then break
		if (parent[sink] == -1) break;


		for (int u = sink; u != source; u = parent[u]) 
		{
			flow[parent[u]][u]--;
			flow[u][parent[u]]++;
		}
		maxflow++;
	}

	cout << n - maxflow << endl;

	return 0;
}