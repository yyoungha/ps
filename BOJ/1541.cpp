#include <iostream>
#include <sstream>
#include <string>
#include <queue>

using namespace std;

queue<string> tokenize(const string& data, const char delimiter = ' ') 
{
	queue<string> result;
	string token;
	stringstream ss(data);

	while (getline(ss, token, delimiter)) 
	{
		result.push(token);
	}
	return result;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;

	queue<string> chunk = tokenize(s, '-');
	queue<string> q;

	int ans = 0;
	int temp;

	q = tokenize(chunk.front(), '+');
	chunk.pop();

	while (!q.empty())
	{
		ans += stoi(q.front());
		q.pop();
	}

	while (!chunk.empty())
	{
		q = tokenize(chunk.front(), '+');
		chunk.pop();

		temp = 0;
		while (!q.empty())
		{
			temp += stoi(q.front());
			q.pop();
		}
		ans -= temp;
	}
	cout << ans;
			
	return 0;
}