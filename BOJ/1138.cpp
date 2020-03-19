#include <iostream>

using namespace std;

int main()
{
	int n;
	int seq[11];
	int ans[11] = { 0, };
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> seq[i];

	int count; // 현재 앞에 큰 숫자가 몇개나 있는가?
	for (int i = 1; i <= n; i++)
	{
		count = seq[i];
		for (int j = 1; j <= n; j++)
		{
			// 1. 다음 칸을 검사
			// 1-1. count가 0이 아닐 때 - 무조건 다음칸으로 가야함(해당 칸이 0이면 count --, 아니면 그냥)
			if (count != 0)
			{
				if (ans[j] == 0) count--;
				continue;
			}
			// 1-2. count가 0이지만 해당 칸에 숫자가 있다 - 다음 칸으로 가야함(j++)
			if (ans[j] != 0) continue;

			// 2. count가 0이고 해당 칸에 숫자가 없으면 그 위치에 숫자를 할당한다.
			ans[j] = i;
			break;
		}
	}


	for (int i = 1; i <= n; i++)
		cout << ans[i] << " ";

	return 0;
}