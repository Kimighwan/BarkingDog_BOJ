#include <iostream>
using namespace std;

int t, n;
int fibo[41][2]; // 숫자 i가 0 or 1을 호출한 횟수

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	fibo[0][0] = 1;
	fibo[1][1] = 1;

	for (int i = 2; i <= 40; i++) {
		fibo[i][0] = fibo[i - 1][0] + fibo[i - 2][0];		
		fibo[i][1] = fibo[i - 1][1] + fibo[i - 2][1];

	}

	cin >> t;
	while (t--)
	{
		cin >> n;

		cout << fibo[n][0] << " " << fibo[n][1] << "\n";
	}
} // dp[0]과 dp[1]이 호출되는 횟수