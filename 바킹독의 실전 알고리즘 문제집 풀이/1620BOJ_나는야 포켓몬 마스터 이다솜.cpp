#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int n, m;
unordered_map<string, int> um;
string s[100'005];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		um[s[i]] = i;
	}

	while (m--) {
		string q;
		cin >> q;
		if (isdigit(q[0]))
			cout << s[stoi(q)] << "\n";
		else
			cout << um[q] << "\n";
	}

} // 이름 출력은 s에서 인덱스로 접근
  // 번호 출력은 map에서 이름으로 검색