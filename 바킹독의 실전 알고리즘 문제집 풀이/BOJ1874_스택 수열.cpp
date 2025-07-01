#include <iostream>
#include <stack>
using namespace std;

int n, cnt = 1;
stack<int> S;
string result = "";

int main() {
	cin >> n;

	while (n--)
	{
		int x; cin >> x;

		while (x >= cnt)
		{
			S.push(cnt++);
			result += "+\n";
		}

		if (S.top() != x)
		{
			cout << "NO";
			return 0;
		}

		S.pop(); result += "-\n";
	}

	cout << result;
}