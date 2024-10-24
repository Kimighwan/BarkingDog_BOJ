#include <iostream>
#include <algorithm>
#include <set>
#include <tuple>
using namespace std;

int n, k;
pair<int, int> p[300003]; // 가격과 무게
multiset<int> bag; // 가방 무게
long long ans = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> p[i].second >> p[i].first;
	}
	sort(p, p + n);

	for (int i = 0; i < k; i++)
	{
		int m;
		cin >> m;
		bag.insert(m);
	}

	for (int i = n - 1; i >= 0; i--) // 가격이 높은 것부터 체크
	{
		int m, v;
		tie(v, m) = p[i];
		auto ite = bag.lower_bound(m);
		if (ite == bag.end()) continue;
		ans += v;
		bag.erase(ite);
	}

	cout << ans;
}