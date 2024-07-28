#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int k, w, h;
int map[201][201];
int dist[32][202][202];
int dkx[] = { -1, 1, -2, 2, -2, 2, -1, 1 };
int dky[] = { 2, 2, 1, 1, -1, -1, -2, -2 };
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> k >> w >> h;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			cin >> map[i][j];

	queue<tuple<int, int, int>> q;
	q.push({ 0, 0, 0 });
	dist[0][0][0] = 1;


	while (!q.empty())
	{
		int curx, cury, curk;
		tie(curk, curx, cury) = q.front();
		q.pop();

		if (k > curk)
		{
			for (int dir = 0; dir < 8; dir++)
			{
				int nx = curx + dkx[dir];
				int ny = cury + dky[dir];
				if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
				if (map[nx][ny] || dist[curk + 1][nx][ny]) continue;
				dist[curk + 1][nx][ny] = dist[curk][curx][cury] + 1;
				q.push({ curk + 1, nx, ny });
			}
		}

		for (int dir = 0; dir < 4; dir++)
		{
			int nx = curx + dx[dir];
			int ny = cury + dy[dir];
			if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
			if (map[nx][ny] || dist[curk][nx][ny]) continue;
			dist[curk][nx][ny] = dist[curk][curx][cury] + 1;
			q.push({ curk, nx, ny });
		}
	}

	int result = 0x7f;
	for (int i = 0; i < k + 1; i++)
		if(dist[i][h - 1][w - 1]) result = min(result, dist[i][h - 1][w - 1]);
	if (result != 0x7f) cout << result - 1;
	else cout << -1;
}