#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	stack<pair<int, int>> s;
	s.push(make_pair(100000001, 0));

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		while (s.top().first < x)
			s.pop();
		cout << s.top().second << " ";
		s.push({ x ,i });
	}
}