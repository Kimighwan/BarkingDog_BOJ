#include <iostream>
using namespace std;

int arr[105];
int cnt = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = n - 2; i >= 0; i--)
	{
		if (arr[i] >= arr[i + 1])
		{
			while (arr[i] >= arr[i + 1])
			{
				arr[i]--; 
				cnt++;
			}
		}
	}

	cout << cnt;
}