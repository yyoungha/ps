#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INT_INF = 2147483647;
const int MAX_SIZE = 1001;
const int MAX_SIZE_2X = MAX_SIZE * 2;

vector<int> vertex[MAX_SIZE_2X];
int parent[MAX_SIZE_2X];
int capacity[MAX_SIZE_2X][MAX_SIZE_2X];
int flow[MAX_SIZE_2X][MAX_SIZE_2X];
int n, m, maxflow = 0;

bool dfs(int s, int sink)
{
	if (s == sink) return true;
	for(auto v : vertex[s])
		if ((capacity[s][v] - flow[s][v] > 0) && (parent[v] == -1))
		{
			parent[v] = s;
			if (dfs(v, sink)) return true;
		}

	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int numOfEdges;

	cin >> n >> m;

	int source = 0,
		sink = n + m + 1,
		can;

	// construct flow network
	for (int i = 1; i <= n; i++)
	{
		cin >> numOfEdges;

		// add edge between source and vertex(worker)
		vertex[source].push_back(i);
		vertex[i].push_back(source);
		capacity[source][i] = 2;

		// add edge between worker(i) and task(n + can)
		for (int j = 0; j < numOfEdges; j++)
		{
			cin >> can;
			vertex[i].push_back(n + can);
			vertex[n + can].push_back(i);
			capacity[i][n + can] = 1;
		}
	}

	// add edge between task(i) and sink
	for (int j = n + 1; j < sink; j++)
	{
		vertex[j].push_back(sink);
		vertex[sink].push_back(j);
		capacity[j][sink] = 1;
	}

	// Edmonds-Karp
	while (1)
	{
		fill(parent, parent + MAX_SIZE_2X, -1);

		dfs(source, sink);

		// no augmenting path then exit
		if (parent[sink] == -1) break;

		// find minimum residual capacity of the augmenting path
		int residualCapacity = INT_INF,
			to, 
			from = sink;

		while (from != source) 
		{
			to = from;
			from = parent[from];
			residualCapacity = std::min(residualCapacity, capacity[from][to] - flow[from][to]);
		}

		// update flow
		from = sink;
		while (from != source) 
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