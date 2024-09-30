#include <iostream>
using namespace std;

int a, b;
int arr1[1'000'001];
int arr2[1'000'001];
int ans[2'000'002];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> a >> b;

	for (int i = 0; i < a; i++)
		cin >> arr1[i];

	for (int i = 0; i < b; i++)
		cin >> arr2[i];

	int aidx = 0, bidx = 0;
	for (int i = 0; i < a + b; i++) 
	{
		if (aidx == a) ans[i] = arr2[bidx++];
		else if (bidx == b) ans[i] = arr1[aidx++];
		else if (arr1[aidx] <= arr2[bidx]) ans[i] = arr1[aidx++];
		else ans[i] = arr2[bidx++];
	}

	for (int i = 0; i < a + b; i++)
		cout << ans[i] << ' ';
}