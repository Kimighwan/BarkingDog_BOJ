#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int n;
unordered_map<string, string> m;
vector<string> ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		string name, log;
		cin >> name >> log;
		m[name] = log;
	}

	for (auto data : m) {
		if (data.second == "enter")
			ans.push_back(data.first);
	}

	sort(ans.begin(), ans.end(), greater<>());

	for (auto i : ans) cout << i << "\n";
}