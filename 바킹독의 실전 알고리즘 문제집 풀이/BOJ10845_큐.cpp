#include <iostream>
#include <queue>
using namespace std;

int n;
queue<int> Q;

int main() {
	cin >> n;

	while (n--)
	{
		string op; cin >> op;

		if (op == "push")
		{
			int x; cin >> x;
			Q.push(x);
		}
		else if (op == "pop")
		{
			if (Q.empty())
				cout << "-1\n";
			else {
				cout << Q.front() << "\n";
				Q.pop();
			}
		}
		else if (op == "size")
			cout << Q.size() << "\n";
		else if (op == "empty")
		{
			if (Q.empty())
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (op == "front")
		{
			if (Q.empty())
				cout << "-1\n";
			else {
				cout << Q.front() << "\n";
			}
		}
		else
		{
			if (Q.empty())
				cout << "-1\n";
			else {
				cout << Q.back() << "\n";
			}
		}
	}
}