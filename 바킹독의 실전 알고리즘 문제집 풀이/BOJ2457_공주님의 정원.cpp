#include <iostream>
#include <vector>
using namespace std;

int n, ans = 0;
vector<pair<int, int>> flower;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) 
	{
		int sm, sd, em, ed;
		cin >> sm >> sd >> em >> ed;
		flower.push_back({ sm * 100 + sd, em * 100 + ed });
	}

	int curT = 301;
	while (curT < 1201)
	{
		int nexT = curT;
		for (int i = 0; i < n; i++)
		{
			if (flower[i].first <= curT && flower[i].second > nexT)
				nexT = flower[i].second;
		}

		if (curT == nexT)
		{
			cout << 0;
			return 0;
		}

		ans++;
		curT = nexT;
	}

	cout << ans;
}