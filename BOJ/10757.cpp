#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define endl '\n'

using namespace std;

int main()
{
	string op1, op2;
	cin >> op1 >> op2;

	vector<int> v1, v2, ans;

	for (int i = 0; i < op1.length(); i++)
		v1.push_back(op1.at(i) - '0');

	for (int i = 0; i < op2.length(); i++)
		v2.push_back(op2.at(i) - '0');

	int a, b;
	int carry = 0;
	while (!v1.empty() && !v2.empty())
	{
		a = v1.back();
		v1.pop_back();
		b = v2.back();
		v2.pop_back();
		ans.push_back((a + b + carry) % 10);
		carry = (a + b + carry) / 10;
	}

	if (v1.empty())
	{
		while (!v2.empty())
		{
			b = v2.back();
			v2.pop_back();

			ans.push_back((b + carry) % 10);
			carry = (b + carry) / 10;
		}
	}
	else
	{
		while (!v1.empty())
		{
			b = v1.back();
			v1.pop_back();

			ans.push_back((b + carry) % 10);
			carry = (b + carry) / 10;
		}
	}

	if (carry) ans.push_back(1);

	while (!ans.empty())
	{
		a = ans.back();
		ans.pop_back();
		cout << a;
	}

	return 0;
}