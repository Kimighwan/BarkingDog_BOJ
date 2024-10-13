#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n;
string x;
vector<long long> v;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		reverse(x.begin(), x.end());
		v.push_back(stoll(x));
	}

	sort(v.begin(), v.end());
	for (auto i : v) cout << i << '\n';
	return 0;
}