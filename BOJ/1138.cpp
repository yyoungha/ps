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

	int count; // ���� �տ� ū ���ڰ� ��� �ִ°�?
	for (int i = 1; i <= n; i++)
	{
		count = seq[i];
		for (int j = 1; j <= n; j++)
		{
			// 1. ���� ĭ�� �˻�
			// 1-1. count�� 0�� �ƴ� �� - ������ ����ĭ���� ������(�ش� ĭ�� 0�̸� count --, �ƴϸ� �׳�)
			if (count != 0)
			{
				if (ans[j] == 0) count--;
				continue;
			}
			// 1-2. count�� 0������ �ش� ĭ�� ���ڰ� �ִ� - ���� ĭ���� ������(j++)
			if (ans[j] != 0) continue;

			// 2. count�� 0�̰� �ش� ĭ�� ���ڰ� ������ �� ��ġ�� ���ڸ� �Ҵ��Ѵ�.
			ans[j] = i;
			break;
		}
	}


	for (int i = 1; i <= n; i++)
		cout << ans[i] << " ";

	return 0;
}