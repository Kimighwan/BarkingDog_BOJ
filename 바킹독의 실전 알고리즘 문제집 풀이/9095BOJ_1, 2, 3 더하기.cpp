#include <iostream>

using namespace std;

int n, t;
int dp[10]; // i + 1 -> 만드는 방법 횟수

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	dp[0] = 1;
	dp[1] = 2;
	dp[2] = 4;

	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 3; i < n; i++)
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

		cout << dp[n - 1] << '\n';
	}
}