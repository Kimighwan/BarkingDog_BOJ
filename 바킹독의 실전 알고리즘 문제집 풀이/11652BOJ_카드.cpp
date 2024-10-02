#include <iostream>
#include <algorithm>
using namespace std;

int n;
int cnt = 0, mxcnt = 0;
long long mxval = -(1ll << 62) - 1;
long long arr[100'001];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	for (int i = 0; i < n; i++)
	{
		if (i == 0 || arr[i] == arr[i - 1])
			cnt++;
		else {
			if (cnt > mxcnt) {
				mxcnt = cnt;
				mxval = arr[i - 1];
			}
			cnt = 1;
		}
	}
	if (cnt > mxcnt) mxval = arr[n - 1];
	cout << mxval;
}