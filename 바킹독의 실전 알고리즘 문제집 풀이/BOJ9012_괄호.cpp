#include <iostream>
#include <stack>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	while (n--)
	{
		string input; cin >> input;
		bool check = false;

		if (input == ".") break;

		stack<char> _stack;

		for (auto i : input)
		{
			if (i == '(')
				_stack.push(i);
			else if (i == ')')
			{
				if (_stack.empty() || _stack.top() != '(')
				{
					check = true;
					break;
				}
				_stack.pop();
			}
		}

		if (_stack.empty() && !check)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}
}