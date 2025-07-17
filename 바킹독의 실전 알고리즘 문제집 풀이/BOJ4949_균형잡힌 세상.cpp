#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (true)
	{
		string input; getline(cin, input);
		bool check = false;

		if (input == ".") break;

		stack<char> _stack;

		for (auto i : input)
		{
			if (i == '(' || i == '[')
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
			else if (i == ']')
			{
				if (_stack.empty() || _stack.top() != '[')
				{
					check = true;
					break;
				}
				_stack.pop();
			}
		}

		if (_stack.empty() && !check)
			cout << "yes" << "\n";
		else
			cout << "no" << "\n";
	}
}