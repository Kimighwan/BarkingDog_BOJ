#include <iostream>
#include <vector>
using namespace std;

int n, cnt = 0;
int m = 123456 * 2;
vector<bool> chk(m + 1, true);

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	chk[1] = false;

	for (int i = 2; i * i <= m; i++)
	{
		if (!chk[i]) continue;

		for (int j = i * i; j <= m; j += i)
		{
			chk[j] = false;
		}
	}

	while (1)
	{
		cin >> n;

		if (!n) break;

		cnt = 0;

		for (int i = n + 1; i <= 2 * n; i++)
		{
			if (chk[i]) cnt++;
		}

		cout << cnt << "\n";
	}
}