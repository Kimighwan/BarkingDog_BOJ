#include <iostream>

using namespace std;

long long a, b, c;

long long Sol(long long b)
{
	if (b == 1) return a % c;
	long long val = Sol(b / 2);
	val = val * val % c;
	if (b % 2 == 0) return val;
	return val * a % c;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b >> c;

	cout << Sol(b);
}