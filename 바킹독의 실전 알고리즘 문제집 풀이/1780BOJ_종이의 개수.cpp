#include <iostream>

using namespace std;

int n;
int map[2200][2200];
int cnt[3];

bool Cnt(int x, int y, int z) {
	for (int i = x; i < x + z; i++)
		for (int j = y; j < y + z; j++)
			if (map[x][y] != map[i][j])
				return false; // 다르다
	return true; // 같다
}

void Solve(int x, int y, int z) {
	if (Cnt(x, y, z))
	{
		cnt[map[x][y] + 1] += 1;
		return;
	}

	int nxt = z / 3;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			Solve(x + i * nxt, y + j * nxt, nxt);
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	Solve(0, 0, n);
	for (int i = 0; i < 3; i++) cout << cnt[i] << '\n';
}