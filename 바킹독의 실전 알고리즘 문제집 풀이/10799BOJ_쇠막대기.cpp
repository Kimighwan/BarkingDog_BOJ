// () 쌍이 바로 나오면 레이저이다.
// ( 로 쇠막대기가 시작이 되고 )로 쇠막대기의 끝을 나타낸다.
// () 기준으로 (의 개수만큼 잘린 조각을 늘린다.
// )가 나오면 잘린 개수가 1개 늘어난다.

#include <iostream>
#include <stack>
using namespace std;
long long cnt = 0;
stack<char> _stack;
int main() {
	string s;
	cin >> s;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
			_stack.push(s[i]);
		else if (!_stack.empty() && s[i] == ')')
		{
			if (s[i - 1] == '(')
			{
				_stack.pop();
				cnt += _stack.size();
			}
			else
			{
				_stack.pop();
				cnt++;
			}
		}
	}
	cout << cnt;
}