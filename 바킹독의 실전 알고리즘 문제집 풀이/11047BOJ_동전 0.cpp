#include <iostream>
using namespace std;

//int n, k;
//int coin[11];
//int cnt = 0;
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//
//	cin >> n >> k;
//	for (int i = 1; i <= n; i++)
//		cin >> coin[i];
//
//	for (int i = n; i > 0; i--) {
//		cnt += k / coin[i];
//		k %= coin[i];
//	}
//
//	cout << cnt;
//}

int n, k, coin[11], result = 0;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}

	for (int i = n - 1; i >= 0; i--) {
		result += k / coin[i];
		k %= coin[i];
	}

	cout << result;
}