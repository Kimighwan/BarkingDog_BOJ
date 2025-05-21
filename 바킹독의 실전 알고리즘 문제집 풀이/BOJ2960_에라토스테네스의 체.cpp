#include <iostream>
#include <vector>
using namespace std;

vector<bool> e(1005, false);
vector<int> chk(1005, 0);
int n, k;
int cnt = 0;

int main() {
	cin >> n >> k;

	for (int i = 2; i <= n; i++)
	{
		if (e[i]) continue;
		e[i] = true;

		cnt++;
		chk[cnt] = i;

		for (int j = i + i; j <= n; j += i)
		{
			if (e[j]) continue;
			e[j] = true;

			cnt++;
			chk[cnt] = j;
		}
	}

	cout << chk[k];
}