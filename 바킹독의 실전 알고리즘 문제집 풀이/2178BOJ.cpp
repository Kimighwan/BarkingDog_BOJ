#include <iostream>
#include <queue>
using namespace std;

int map[101][101];
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int dist[101][101];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		for (int j = 0; j < m; j++)
			map[i][j] = tmp[j] - '0';
	}

	queue<pair<int, int>> q;
	dist[0][0] = 1;
	q.push({ 0, 0 });
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (map[nx][ny] == 0 || dist[nx][ny] != 0) continue;
			dist[nx][ny] = dist[x][y] + 1;
			q.push({ nx, ny });
		}
	}
	cout << dist[n - 1][m - 1];
}