#include <iostream>
using namespace std;

int D[1'000'000];
int n;

int main() {
	D[1] = 0;

	cin >> n;
	for (int i = 2; i <= n; i++) {
		D[i] = D[i - 1] + 1;
		if (i % 2 == 0) D[i] = min(D[i], D[i / 2] + 1);
		if (i % 3 == 0) D[i] = min(D[i], D[i / 3] + 1);
	}
	cout << D[n];
}