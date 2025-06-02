#include <iostream>
using namespace std;

int arr[7][2];
int n, k;
int cnt = 0;

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		int s, y;
		cin >> s >> y;
		arr[y][s]++;
	}

	for (int i = 1; i <= 6; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			if (arr[i][j] > 0)
			{
				cnt += arr[i][j] / k;
				if (arr[i][j] % k != 0) cnt++;
			}
		}
	}

	cout << cnt;
}