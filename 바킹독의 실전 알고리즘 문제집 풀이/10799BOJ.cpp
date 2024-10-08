#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	stack<char> s;
	long long result = 0;
	string input;

	cin >> input;

	for (int i =0; i < input.size(); i++)
	{
		if (input[i] == '(')
			s.push(input[i]);
		else if (!s.empty() && input[i] == ')')
		{
			if (input[i - 1] == '(') {
				s.pop();
				result += s.size();
			}
			else { 
				s.pop();  
				result++; 
			}
		}
	}
	cout << result;
}