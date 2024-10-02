// 짧은 거 먼저
// 길이 같으면 모든 자리수의 합이 작은 게 먼저(숫자만 더하기)
// 아니면 사전순 비교
#include <iostream>
#include <cctype>
#include <algorithm>
#include <vector>
using namespace std;

int n;
string str;
vector<string> v;

// 작은게 true;
bool Cmp(string& a, string& b) {
	int alen = a.size(), blen = b.size();
	int asum = 0, bsum = 0;
	if (alen != blen) return alen < blen;
	
	for (int i = 0; i < alen; i++)
		if (isdigit(a[i])) asum += a[i] -'0';
	
	for (int i = 0; i < blen; i++)
		if (isdigit(b[i])) bsum += b[i] - '0';

	if (asum != bsum) return asum < bsum;
	return a < b;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		v.push_back(str);
	}

	sort(v.begin(), v.end(), Cmp);

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << '\n';
}