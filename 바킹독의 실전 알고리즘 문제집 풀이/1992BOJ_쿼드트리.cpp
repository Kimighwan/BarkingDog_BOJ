#include <iostream>
using namespace std;

char map[64][64];
string result;

bool Check(int x, int y, int n) {
	for (int i = x; i < x + n; i++)
		for (int j = y; j < y + n; j++)
			if (map[x][y] != map[i][j]) return false;
	return true;
}

void Solve(int x, int y, int n) {
	if (Check(x, y, n))
	{
		result += map[x][y];
		return;
	}

	result += "(";
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
			Solve(x + i * n / 2, y + j * n / 2, n / 2);
	result += ")";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	Solve(0, 0, n);
	cout << result;
}