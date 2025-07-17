#include <iostream>
#include <stack>
using namespace std;

int n, cnt = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	while (n--)
	{
		string input; cin >> input;
		stack<char> _stack;

		for (auto i : input)
		{
			if (!_stack.empty() && i == _stack.top()) _stack.pop();
			else _stack.push(i);
		}

		if (_stack.empty()) cnt++;
	}

	cout << cnt;
}