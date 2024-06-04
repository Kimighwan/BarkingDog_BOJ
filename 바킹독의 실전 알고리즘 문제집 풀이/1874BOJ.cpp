#include <iostream>
#include <stack>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, cnt = 1;
	cin >> n;
	stack<int> s;
	string ans;

	while (n--) {
		int x;
		cin >> x;
		while (cnt <= x)
		{
			s.push(cnt++);
			ans += "+\n";
		}
		if (s.top() != x)
		{
			cout << "NO\n";
			return 0;
		}
		s.pop();
		ans += "-\n";
	}
	cout << ans;
}