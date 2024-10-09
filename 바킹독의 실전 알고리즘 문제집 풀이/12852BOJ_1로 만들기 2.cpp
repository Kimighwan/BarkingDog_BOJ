#include <iostream>
using namespace std;

int n;
int dp[1000005];
int path[1000005];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	dp[1] = 0;
	path[1] = 0;
	for (int i = 2; i <= n; i++){
		dp[i] = dp[i - 1] + 1;
		path[i] = i - 1;

		if (i % 2 == 0 && dp[i] > dp[i / 2]  + 1) {
			dp[i] = min(dp[i], dp[i / 2] + 1);
			path[i] = i / 2;
		}

		if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
			dp[i] = min(dp[i], dp[i / 3] + 1);
			path[i] = i / 3;
		}
	}

	cout << dp[n] << '\n';
	int cur = n;
	while (cur != 0) {
		cout << cur << ' ';
		cur = path[cur];
	}
}