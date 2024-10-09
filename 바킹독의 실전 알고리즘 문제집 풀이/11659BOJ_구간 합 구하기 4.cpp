#include <iostream>
using namespace std;

int dp[100001];
int n, m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> dp[i];
        dp[i] += dp[i - 1];
    }

    while (m--)
    {
        int st, end;
        cin >> st >> end;
        cout << dp[end] - dp[st - 1] << '\n';
    }
}
