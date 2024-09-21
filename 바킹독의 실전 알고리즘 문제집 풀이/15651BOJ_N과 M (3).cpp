#include <iostream>
using namespace std;

int n, m;
int ans[10];

void Solve(int cur) {
	if (cur == m) {
		for (int i = 0; i < m; i++)
			cout << ans[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		ans[cur] = i;
		Solve(cur + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	Solve(0);
}