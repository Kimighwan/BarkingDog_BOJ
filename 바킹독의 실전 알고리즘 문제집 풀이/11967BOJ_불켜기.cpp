#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

int n, m, x, y, a, b;
int visit[102][102];
int map[102][102]; // ∫“ »Æ¿Œ
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
vector <pair<int, int>> adj[101][101];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y >> a >> b;
		adj[x][y].push_back({ a, b });
	}

	queue<pair<int, int>> q;
	q.push({ 1,1 });
	map[1][1] = 1;
	visit[1][1] = 1;
	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		for (auto nxt : adj[cur.first][cur.second])
		{
			if (visit[nxt.first][nxt.second]) continue;
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = nxt.first + dx[dir];
				int ny = nxt.second + dy[dir];
				if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
				if (visit[nx][ny])
				{
					visit[nxt.first][nxt.second] = 1;
					q.push({ nxt.first, nxt.second });
				}
			}
			map[nxt.first][nxt.second] = 1;

		}

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];
			if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
			if (visit[nx][ny] || map[nx][ny] == 0) continue;
			visit[nx][ny] = 1;
			q.push({ nx, ny });				
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) ans += map[i][j];
	cout << ans;
}
