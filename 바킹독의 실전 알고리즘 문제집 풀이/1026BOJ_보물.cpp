#include <iostream>
#include <algorithm>
using namespace std;

int n;
int a[51];
int b[51];
int ans = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];

	sort(a, a + n);
	sort(b, b + n);
	for (int i = 0; i < n; i++)
		ans += a[i] * b[n - 1 - i];
	cout << ans;
}