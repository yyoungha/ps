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
		for (int want_pos : cow[pos]) // �Ұ� ���ϴ� �� ��翡 ���Ͽ�
			if (!barn[want_pos] || solve(barn[want_pos])) // 1) ��簡 ����ְų�  2) �ٸ� �Ҹ� �Ű� �� ���� ��� �� ������
			{
				barn[want_pos] = pos; // �Ҹ� �� ��翡 �����Ѵ�.
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

	for (int i = 1; i <= n; i++) // ������ �� �Ѹ����� ���Ͽ�
	{
		fill(visited, visited + n, false);
			   
		if (solve(i)) cnt++;
	}

	cout << cnt << endl;

	return 0;
}