#include <iostream>
#include <algorithm>
using namespace	std;

int n, m;
int arr[100'001];

int F(int v) {
	int s = 0;
	int e = n - 1;

	while (s <= e) {
		int m = (s + e) / 2;

		if (arr[m] < v)
			s = m + 1;
		else if (arr[m] > v)
			e = m - 1;
		else
			return 1;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	cin >> m;
	while (m--)
	{
		int val;
		cin >> val;
		cout << F(val) << "\n";
	}

}