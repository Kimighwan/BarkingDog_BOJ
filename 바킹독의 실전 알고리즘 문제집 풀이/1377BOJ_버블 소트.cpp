#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<int, int> p[500001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	int x;
	for (int i = 0; i < n; i++) {
		cin >> p[i].first;
		p[i].second = i;
	}

	sort(p, p + n);

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (i < p[i].second) ans = max(ans, p[i].second - i);
	}

	cout << ans + 1;
}
    