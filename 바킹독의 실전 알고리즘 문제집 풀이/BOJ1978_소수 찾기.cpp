#include <iostream>
using namespace std;

int cnt = 0;

int F(int num) {

	if (num == 1) return 0;

	for (int i = 2; i * i <= num; i++)
	{
		if (num % i == 0) return 0;
	}

	return 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	while (n--)
	{
		int x; cin >> x;

		cnt += F(x);
	}

	cout << cnt;
}