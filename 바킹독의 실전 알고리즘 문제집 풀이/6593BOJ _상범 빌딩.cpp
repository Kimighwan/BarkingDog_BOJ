#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int l, r, c;
int dist[31][31][31];
int dx[] = { 1, -1, 0, 0, 0, 0 };
int dy[] = { 0, 0, 1, -1, 0, 0 };
int dz[] = { 0, 0, 0, 0, 1, -1 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (1) 
	{
		cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0) break;

		queue<pair<pair<int, int>, int>> q;
		char map[31][31][31];
		bool escape = false;

		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				fill(dist[i][j], dist[i][j] + c, -1);
			}
		}

		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < r; j++)
			{
				for (int k = 0; k < c; k++)
				{
					cin >> map[i][j][k];
					if (map[i][j][k] == 'S')
					{
						dist[i][j][k] = 0;
						q.push({ {i, j} , k });
					}
				}
			}
		}

		while (!q.empty())
		{
			if (escape) break;
			int z = q.front().first.first;
			int y = q.front().first.second;
			int x = q.front().second;
			q.pop();
			for (int d = 0; d < 6; d++)
			{
				int nx = x + dx[d];
				int ny = y + dy[d];
				int nz = z + dz[d];

				if (map[nz][ny][nx] == '#') continue;
				if (dist[nz][ny][nx] != -1) continue;
				if (nz < 0 || ny < 0 || nx < 0 || nz >= l || ny >= r || nx >= c) continue;
				dist[nz][ny][nx] = dist[z][y][x] + 1;

				if (map[nz][ny][nx] == 'E') {
					escape = true;
					cout << "Escaped in " << dist[nz][ny][nx] << " minute(s).\n";
					break;
				}

				q.push({ {nz, ny}, nx });
			}
		}
		while (!q.empty()) q.pop();
		if(!escape) cout << "Trapped!" << "\n";
	}
}