#include <iostream>
#include <algorithm>
using namespace std;

int T, n;
int input[1000001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;

	while (T--) 
	{
		cin >> n;
		for (int i = 0; i < n; i++) cin >> input[i];

		int maxValue = input[n - 1];
		long long result = 0;

		for (int i = n - 2; i >= 0; i--)
		{
			if (input[i] > maxValue) maxValue = input[i];
			result += maxValue - input[i];
		}

		cout << result << '\n';
	}
}