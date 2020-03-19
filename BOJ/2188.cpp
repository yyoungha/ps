#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_SIZE = 201;
vector<int> cow[MAX_SIZE];
int barn[MAX_SIZE];
bool visited[MAX_SIZE];

bool solve(int pos)
{
	if (!visited[pos])
	{
		visited[pos] = true;
		for (int want_pos : cow[pos]) // 소가 원하는 각 축사에 대하여
			if (!barn[want_pos] || solve(barn[want_pos])) // 1) 축사가 비어있거나  2) 다른 소를 옮겨 그 방을 비울 수 있으면
			{
				barn[want_pos] = pos; // 소를 그 축사에 배정한다.
				return true;
			}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, s, 
		want,
		cnt = 0;

	cin >> n >> m;

	// initialize
	for (int i = 1; i <= n; i++)
	{
		barn[i] = 0;
		cin >> s;
		for (int j = 0; j < s; j++)
		{
			cin >> want;
			cow[i].push_back(want);
		}
	}

	for (int i = 1; i <= n; i++) // 각각의 소 한마리에 대하여
	{
		fill(visited, visited + n, false);
			   
		if (solve(i)) cnt++;
	}

	cout << cnt << endl;

	return 0;
}