#include <iostream>
using namespace std;

int n, mx = 0;
int s[10], w[10];
int cnt = 0; // 현재 깨진 계란 수

void Solve(int index) // index 번째 계란으로 깰 차례
{
	if (index == n) {
		mx = max(mx, cnt);
		return;
	}

	if (s[index] <= 0 || cnt == n -1) {
		Solve(index + 1);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (index == i || s[i] <= 0) continue;
		s[index] -= w[i];
		s[i] -= w[index];
		if (s[index] <= 0) cnt++;
		if (s[i] <= 0) cnt++;
		Solve(index + 1);
		if (s[index] <= 0) cnt--;
		if (s[i] <= 0) cnt--;
		s[i] += w[index];
		s[index] += w[i];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie();

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> s[i] >> w[i];

	Solve(0);
	cout << mx;
}