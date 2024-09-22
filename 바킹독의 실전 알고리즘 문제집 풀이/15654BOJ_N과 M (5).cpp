#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[10];
int ans[10];
bool isUsed[10];

void Solve(int cur) {
	if (cur == m) {
		for (int i = 0; i < m; i++)
			cout << arr[ans[i]] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (!isUsed[i])
		{
			ans[cur] = i;
			isUsed[i] = true;
			Solve(cur + 1);
			isUsed[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);
	Solve(0);
}