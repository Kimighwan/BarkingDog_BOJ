#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, x, ans = 0;
priority_queue<int, vector<int>, greater<int>> q;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		q.push(x);
	}

	while (q.size() > 1)
	{
		int x = q.top(); q.pop();
		int y = q.top(); q.pop();
		ans += x + y;
		q.push(x + y);
	}
	cout << ans;
}