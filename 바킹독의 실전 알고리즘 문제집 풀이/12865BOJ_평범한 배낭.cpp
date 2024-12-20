#include <iostream>
using namespace std;

int n, k;
int w[101];
int v[101];
int dp[101][100'005];  // dp[i][j] = 무게가 j일 때 i번째 물건 선택시 가치 값

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		cin >> w[i] >> v[i];

	for (int i = 0; i <= n; i++) // 무게 0일 때 초기값
		dp[i][0] = 0;

	for (int i = 0; i <= k; i++) // 선택한 게 없을 때 초기값
		dp[0][i] = 0;


	for (int j = 1; j <= k; k++)
	{
		for(int i = 1; i <= n; i++)
		{
			if (w[i] > j) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
		}
	}

	cout << dp[n][k];
}