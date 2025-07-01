#include <iostream>
#include <stack>
using namespace std;

int k, sum = 0;
stack<int> S;

int main() {
	cin >> k;

	while(k--)
	{
		int x; cin >> x;
		if (x == 0)
		{
			S.pop();
		}
		else
		{
			S.push(x);
		}
	}

	while (!S.empty())
	{
		sum += S.top();
		S.pop();
	}

	cout << sum;
}