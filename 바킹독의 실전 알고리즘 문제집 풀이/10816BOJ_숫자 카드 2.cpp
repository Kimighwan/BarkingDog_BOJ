#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[500'001];

int UpperIndex(int v, int len) {
	int s = 0;
	int e = len;
	while (s < e) {
		int mid = (s + e) / 2;
		if(arr[mid] > v)
			e = mid;
		else
			s = mid + 1;
	}
	return s;
}

int LowerIndex(int v, int len) {
	int s = 0;
	int e = len;
	while (s < e) {
		int mid = (s + e) / 2;
		if (arr[mid] >= v)
			e = mid;
		else
			s = mid + 1;
	}
	return s;
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
		cout << UpperIndex(val, n) - LowerIndex(val, n) << " ";
	}
}