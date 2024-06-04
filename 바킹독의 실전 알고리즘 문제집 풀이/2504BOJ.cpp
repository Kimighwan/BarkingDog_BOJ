#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string input;
	cin >> input;
	stack<char> s;

	int sum = 0;
	int mul = 1;

	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == '(')
		{
			mul *= 2;
			s.push(input[i]);
		}
		else if (input[i] == '[')
		{
			mul *= 3;
			s.push(input[i]);
		}
		else if (input[i] == ')')
		{
			if (s.empty() || s.top() != '(')
			{
				std::cout << 0;
				return 0;
			}
			if(input[i - 1] == '(')	sum += mul;

			s.pop();
			mul /= 2;
		}
		else 
		{
			if (s.empty() || s.top() != '[')
			{
				std::cout << 0;
				return 0;
			}
			if(input[i-1] == '[') sum += mul;
			s.pop();
			mul /= 3;
		}
	}
	if (s.empty())std::cout << sum;
	else cout << 0;
}