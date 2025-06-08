#include <iostream>
#include <stack>
using namespace std;

int n;
stack<int> S;

int main() {
	cin >> n;

	while (n--)
	{
		string s; cin >> s;

		if (s == "push")
		{
			int x; cin >> x;
			S.push(x);
		}
		else if (s == "pop")
		{
			if (S.empty())
				cout << -1 << "\n";
			else
			{
				cout << S.top() << "\n";
				S.pop();
			}
		}
		else if (s == "top")
		{
			if (S.empty())
				cout << -1 << "\n";
			else
				cout << S.top() << "\n";
		}
		else if (s == "size")
		{
			cout << S.size() << "\n";
		}
		else if (s == "empty")
		{
			if (S.empty())
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
	}
}