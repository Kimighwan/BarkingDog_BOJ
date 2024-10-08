#include <iostream>
using namespace std;

int n;
int s[305];
int d[305]; // i번째 계단까지 올라섰을 때 점수 합의 최솟값 // i번째 계단은 밟지 않은 상태
int total = 0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
		total += s[i];
	}

	if (n <= 2)
	{
		cout << total;
		return 0;
	}

	d[1] = s[1];
	d[2] = s[2];
	d[3] = s[3];
	

	for (int i = 4; i < n; i++)
	{
		d[i] = min(d[i - 2], d[i - 3]) + s[i];
	}
	cout << total - min(d[n - 2], d[n - 1]);
}