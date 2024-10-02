#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, c, x;
vector<pair<int, int>> v; // {cnt, num}

bool Cmp(const pair<int, int>& a, const pair<int, int>& b) {
	return a.first > b.first;
}

int main() { // use of stable sort  // 빈도 수가 많은게 앞으로 // 같으면 원본 순서
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> c;

	for (int i = 0; i < n; i++) {
		cin >> x;
		bool chk = false;
		for (auto &a : v) {
			if (a.second == x)
			{
				chk = true;
				a.first++;
				break;
			}
		}
		if (!chk) v.push_back({ 1, x });
	}
	stable_sort(v.begin(), v.end(), Cmp);
	for (auto i : v)
		while (i.first--) cout << i.second << ' ';
}