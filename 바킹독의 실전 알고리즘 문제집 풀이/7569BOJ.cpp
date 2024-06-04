#include <iostream>
#include <queue>
using namespace std;

int n, m, h;
int map[101][101][101];
int dx[] = { 1, -1, 0, 0, 0, 0 };
int dy[] = { 0, 0, 1, -1, 0, 0 };
int dz[] = { 0, 0, 0, 0, 1, -1 };
int result = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> m >> n >> h;
	queue<pair<pair<int, int>, int>> q;

	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> map[i][j][k];
				if (map[i][j][k] == 1)
					q.push({ { i, j }, k });
			}
		}
	}


	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int z = q.front().second;
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m || nz < 0 || nz >= h) continue;
			if (map[nx][ny][nz] != 0) continue;
			map[nx][ny][nz] = map[x][y][z] + 1;
			q.push({ { nx, ny }, nz });
		}
	}

	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j][k] == 0)
				{
					cout << -1;
					return 0;
				}
				result = max(result, map[i][j][k]);
			}
		}
	}

	cout << result - 1;
}