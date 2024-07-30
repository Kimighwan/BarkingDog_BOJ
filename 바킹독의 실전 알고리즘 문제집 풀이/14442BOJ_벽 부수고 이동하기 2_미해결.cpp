#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int k, n, m;
string map[1002];
int dist[12][1002][1002];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		cin >> map[i];

	dist[0][0][0] = 1;
	queue<tuple<int, int, int>> q;
	q.push({ 0, 0, 0 });

	while (!q.empty())
	{
		int curx, cury, curk;
		tie(curk, curx, cury) = q.front();
		q.pop();
		if (curx == n - 1 && cury == m - 1)
		{
			cout << dist[curk][curx][cury];
			return 0;
		}
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = curx + dx[dir];
			int ny = cury + dx[dir];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

			int nk = curk;
			if (map[nx][ny] == '1') nk++;
			if (nk > k || dist[nk][nx][ny] > 0) continue;
			dist[nk][nx][ny] = dist[curk][curx][cury] + 1;
			q.push({ nk, nx, ny });
		}
	}
	cout << -1;
}