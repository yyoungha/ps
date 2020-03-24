#include <iostream>
#include <vector>
using namespace std;

const int mod = 1000000007;

vector<vector<long long>> operator * (const vector<vector<long long>>& a, const vector<vector<long long>>& b)
{
	int n = a.size();
	vector<vector<long long>> c(n, vector<long long>(n));
	for(int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++)
				c[i][j] += a[i][k] * b[k][j];
			c[i][j] %= mod;
		}
	return c;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	long long n;
	cin >> n;

	if (n <= 1) {
		cout << n << endl;
		return 0;
	}

	vector<vector<long long>> ans = { {1, 0}, {0, 1} };
	vector<vector<long long>> a = { {1, 1}, {1, 0} };

	while (n > 0) {
		if (n % 2 == 1) {
			ans = ans * a;
		}
		a = a * a;
		n /= 2;
	}

	cout << ans[0][1] << endl;	
	return 0;
}