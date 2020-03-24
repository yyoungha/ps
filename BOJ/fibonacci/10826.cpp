#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string arr[10001] = { "0", "1" };

string bigIntSum(const string& op1, const string& op2)
{
	string sum(max(op1.size(), op2.size()), '0');
	int carry = 0, num;
	
	for (int i = 0; i < sum.size(); i++) {
		num = 0;

		if (i < op1.size()) num += op1[op1.size() - i - 1] - '0';
		if (i < op2.size()) num += op2[op2.size() - i - 1] - '0';

		sum[sum.size() - i - 1] = ((num + carry) % 10) + '0';
		carry = (num + carry) / 10;
	}

	if (carry) sum.insert(sum.begin(), '1');

	return sum;
}

string fib(int n)
{
	if (n <= 1) return arr[n];

	for (int i = 2; i <= n; i++) {
		arr[i] = bigIntSum(arr[i - 1], arr[i - 2]);
	}

	return arr[n];
}

int main()
{
	int n;
	cin >> n;
	cout << fib(n) << endl;
	return 0;
}