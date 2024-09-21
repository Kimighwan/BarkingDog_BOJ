#include <iostream>
using namespace std;

int n, m;
int ans[10];
bool isUsed[10];

void Solve(int cur) {
	if (cur == m) {
		for (int i = 0; i < m; i++)
			cout << ans[i] << ' ';
		cout << '\n';
		return;
	}

	int start = 1;
	if (cur != 0) start = ans[cur - 1] + 1;
	for (int i = start; i <= n; i++)
	{
		if (isUsed[i]) continue;
		isUsed[i] = true;
		ans[cur] = i;
		Solve(cur + 1);
		isUsed[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	Solve(0);
}