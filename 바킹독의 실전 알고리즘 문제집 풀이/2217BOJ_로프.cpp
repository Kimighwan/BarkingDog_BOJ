#include <iostream>
#include <algorithm>
using namespace std;

int n, w[100'005];
int total = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> w[i];
	}

	for (int i = 1; i <= n; i++)
	{
		total = max(total, w[n - i] * i);
	}

	cout << total;


	/*cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> w[i];

	sort(w + 1, w + n + 1, greater<>());

	for (int k = 1; k <= n; k++) {
		total = max(total, k * w[k]);
	}

	cout << total;*/
}