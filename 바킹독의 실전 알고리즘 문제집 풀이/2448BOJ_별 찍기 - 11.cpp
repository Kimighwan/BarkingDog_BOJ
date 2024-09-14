#include <iostream>

using namespace std;

char map[3100][3100 * 2];

void Solve(int x, int y, int n) {
	if (n == 3) {
		map[x][y] = '*';
		map[x + 1][y + 1] = '*', map[x + 1][y - 1] = '*';
		for (int i = y - 2; i <= y + 2; i++)
			map[x + 2][i] = '*';
		return;
	}
	Solve(x, y, n / 2);
	Solve(x + n / 2, y - n / 2, n / 2);
	Solve(x + n / 2, y + n / 2, n / 2);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	Solve(0, n - 1, n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n * 2 - 1; j++)
		{
			if (map[i][j] == '*')
				cout << '*';
			else
				cout << ' ';
		}
		cout << '\n';
	}
}