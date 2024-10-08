#include <iostream>
using namespace std;

int n;
int R[1005];
int G[1005];
int B[1005];
int d[1005][3];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> R[i] >> G[i] >> B[i];

	d[1][0] = R[0];
	d[1][1] = G[0];
	d[1][2] = B[0];

	for (int i = 1; i <= n; i++)
	{
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + R[i];
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + G[i];
		d[i][2] = min(d[i - 1][0], d[i - 1][1]) + B[i];
	}

	cout << min(min(d[n][0], d[n][1]), d[n][2]);



}