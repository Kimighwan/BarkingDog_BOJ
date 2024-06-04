#include <iostream>
#include <stack>
using namespace std;
int main() {
	ios::ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1)
	{
		int n;
		cin >> n;
		if (n == 0) break;
		stack<pair<long long, long long>> s;
		long long result = 0;
		long long h;
		for (int i = 0; i < n; i++)
		{
			cin >> h;
			int index = i;
			while (!s.empty() && s.top().first >= h)
			{
				result = max(result, (i - s.top().second) * s.top().first);
				index = s.top().second;
				s.pop();
			}
			s.push({ h, i });
			while (!s.empty())
			{
				result = s.top().first * ()
			}
		}
	}
}