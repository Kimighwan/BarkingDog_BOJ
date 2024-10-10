#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
pair<int, int> p[100001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i].second >> p[i].first; // fist가 끝나는 시간 .. seconde가 시작하는 시간

	sort(p, p + n);

	int cnt = 0;
	int t = 0;
	for (int i = 0; i < n; i++)
	{
		if (t <= p[i].second) {
			t = p[i].first;
			cnt++;
		}
	}

	cout << cnt;
}