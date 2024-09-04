#include <iostream>

using namespace std;

void F(int a, int b, int n) {
	if (n == 1)
	{
		cout << a << " " << b << "\n";
		return;
	}
	F(a, 6 - a - b, n - 1);
	cout << a << " " << b << '\n';
	F(6 - a - b, b, n - 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int k;
	cin >> k;
	cout << (1 << k) - 1 << '\n';
	F(1, 3, k);
}