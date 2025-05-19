#include <iostream>
using namespace std;

int l, p, v;
int cnt = 0;
int main() {
	cin.tie(0);

	while (1)
	{
		cin >> l >> p >> v;

		if (l == 0 || p == 0 || v == 0) break;

		cout << "Case " << ++cnt << ": " << ((v / p) * l) + min(v % p, l) << "\n";
	}
}