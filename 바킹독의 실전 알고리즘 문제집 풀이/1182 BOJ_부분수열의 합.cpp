#include <iostream>
using namespace std;

int n, s;
int arr[21];
int cnt = 0;

void Solve(int cur, int total) {
	if (cur == n) {
		if (total == s) cnt++;
		return;
	}

	Solve(cur + 1, total);
	Solve(cur + 1, total + arr[cur]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> s;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	Solve(0, 0);

	if (s == 0) cnt--;
	cout << cnt;
}