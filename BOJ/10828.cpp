#include <iostream>
#include <string>
#include <stack>
#define endl '\n'

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	string cmd;
	int num;
	stack<int> s;

	while (n--)
	{
		cin >> cmd;
		if (cmd == "push") {
			cin >> num;
			s.push(num);
		}
		else if (cmd == "pop") {
			if (s.empty()) {
				cout << -1 << endl;
				continue;
			}
			cout << s.top() << endl;
			s.pop();
		}
		else if (cmd == "size") {
			cout << s.size() << endl;
		}
		else if (cmd == "empty") {
			cout << s.empty() << endl;
		}
		else {
			if (s.empty()) {
				cout << -1 << endl;
				continue;
			}
			cout << s.top() << endl;
		}
	}

	return 0;
}