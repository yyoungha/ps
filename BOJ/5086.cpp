#include <iostream>
#define endl '\n'

using namespace std;

void solve(int a, int b)
{
	if (b % a == 0) cout << "factor" << endl;
	else if (a % b == 0) cout << "multiple" << endl;
	else cout << "neither" << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b;
	while(true)
	{
		cin >> a >> b;
		if (a == 0) break;
		solve(a, b);

	} 

	return 0;
}