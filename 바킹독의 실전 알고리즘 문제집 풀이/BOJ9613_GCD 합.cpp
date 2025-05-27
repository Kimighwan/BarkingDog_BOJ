#include <iostream>
using namespace std;

int t;
int input[101];

int GCD(int a, int b) {
	if (b == 0) return a;
	else {
		return GCD(b, a % b);
	}
}

int main() {
	cin.tie(0);

	cin >> t;

	while (t--)
	{
		int n; cin >> n;

		for (int i = 0; i < n; i++)
			cin >> input[i];

		long long ans = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				ans += GCD(input[i], input[j]);
			}
		}
		

		cout << ans << "\n";
	}
}