#include <iostream>
#include <queue>
using namespace std;

int t, x, y, xx, yy;
int map[301][301];
int dx[] = { -2,-1,1,2,-2,-1,1,2 };
int dy[] = { 1,2,2,1,-1,-2,-2,-1 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			fill(map[i], map[i] + n, -1);

		queue<pair<int, int>> q;
		cin >> x >> y;
		map[x][y] = 0;
		q.push({ x, y });

		cin >> xx >> yy;

		while (!q.empty())
		{
			auto cur = q.front(); q.pop();
			for (int i = 0; i < 8; i++)
			{
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
				if (map[nx][ny] >= 0) continue;
				map[nx][ny] = map[cur.first][cur.second] + 1;
				q.push({ nx, ny });
			}
		}
		cout << map[xx][yy] << '\n';
	}
}