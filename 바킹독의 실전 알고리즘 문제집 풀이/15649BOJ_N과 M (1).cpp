#include <iostream>
using namespace std;

int n, m;
int arr[9];
bool isUsed[9];

void Solve(int k) {
	if (k == m)
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++)
	{
		if (!isUsed[i])
		{
			arr[k] = i;
			isUsed[i] = true;
			Solve(k + 1);
			isUsed[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	Solve(0);
}