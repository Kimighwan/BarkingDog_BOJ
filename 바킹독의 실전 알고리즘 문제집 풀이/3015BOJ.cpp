#include <iostream>
#include <stack>

using namespace std;

int n;
stack<pair<int, int>> s;
long long result;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	while (n--) {
		int h;
		cin >> h;
		int cnt = 1;
		while (!s.empty() && s.top().first <= h)
		{
			result += s.top().second;
			if (s.top().first == h) cnt += s.top().second;
			s.pop();
		}
		if (!s.empty()) result++;
		s.push({ h, cnt });
	}
	cout << result;
}