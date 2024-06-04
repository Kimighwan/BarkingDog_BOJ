#include <iostream>
#include <stack>

using namespace std;

int n;
int a[1000001];
int result[1000001];
stack<int> s;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) cin >> a[i];

	for (int i = n - 1; i >= 0; i--)
	{
		while (!s.empty() && s.top() <= a[i]) s.pop();

		if (s.empty())
			result[i] = -1;
		else
			result[i] = s.top();

		s.push(a[i]);
	}

	for (int i = 0; i < n; i++) cout << result[i] << " ";
}