#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[10];
int ans[10];

void F(int idx, int start) {
	if (idx == m) {
		for (int i = 0; i < m; i++)
			cout << ans[i] << ' ';
		cout << "\n";
		return;
	}
	
	int tmp = 0;

	for (int i = start; i < n; i++) {
		if (tmp == arr[i]) continue;
		ans[idx] = arr[i];
		tmp = ans[idx];
		F(idx + 1, i + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	F(0, 0);
	
}