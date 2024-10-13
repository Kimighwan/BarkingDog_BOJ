#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[8];
int ans[8];

void F(int idx) {
	if (idx == m) {
		for (int i = 0; i < m; i++)
			cout << ans[i] << " ";
		cout << "\n";
		return;
	}

	int pre = 0;
	for (int i = 0; i < n; i++)
	{
		if (pre == arr[i]) continue;
		ans[idx] = arr[i];
		pre = ans[idx];
		F(idx + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);
	F(0);


}

// 숫자 여러변 선택 가능 
// 같은 수열 X
// 순서 있음