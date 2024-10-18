#include <iostream>
using namespace std;

int n, k;
int dp[1001][1001]; // iCj

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		dp[i][0] = dp[i][i] = 1;
		for (int j = 1; j < i; j++)
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % 10007;
	}
	cout << dp[n][k];
}