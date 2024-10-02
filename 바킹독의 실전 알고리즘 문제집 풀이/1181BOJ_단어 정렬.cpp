#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	vector<string> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end(), [](const string& a, const string& b) {
		int alen = a.size();
		int blen = b.size();
		if (alen != blen) return alen < blen;
		return a < b;
		});

	v.erase(unique(v.begin(), v.end()), v.end());
	for (auto a : v) cout << a << '\n';
}