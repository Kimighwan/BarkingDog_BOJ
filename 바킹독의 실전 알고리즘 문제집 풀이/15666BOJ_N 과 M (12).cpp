#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[10];
int result[10];

void F(int cur, int start) {
	if (cur == m) {
		for (int i = 0; i < m; i++) cout << result[i] << " ";
		cout << "\n";
		return;
	}

	int tmp = 0;
	for (int i = start; i < n; i++) {
		if(arr[i] != tmp){
			result[cur] = arr[i];
			tmp = result[cur];
			F(cur + 1, i);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	F(0, 0);
}