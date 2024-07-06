#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int m, n;
char map[1001][1001];
int dist[1001][1001][2];
int dx[4] = { 0 , 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int BFS() {
	dist[0][0][0] = dist[0][0][1] = 1;
	queue<tuple<int, int, int>> q;
	q.push({ 0,0,0 });
	while (!q.empty())
	{
		int x, y, broken;
		tie(x, y, broken) = q.front();
		if (x == n - 1 && y == m - 1) return dist[x][y][broken];
		q.pop();
		int nextdist = dist[x][y][broken] + 1;
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (x < 0 || y < 0 || x >= n || y >= m) continue;
			if (map[nx][ny] == '0' && dist[nx][ny][broken] == 0)
			{
				dist[nx][ny][broken] = nextdist;
				q.push({ nx, ny, broken });
			}
			if (!broken && map[nx][ny] == '1' && dist[nx][ny][1] == 0)
			{
				dist[nx][ny][1] = nextdist;
				q.push({ nx, ny, 1 }); 
			}
		}
	}
	return -1;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];

	cout << BFS();
}
